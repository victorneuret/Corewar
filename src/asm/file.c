/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** file.c
*/

#include "asm/asm.h"

static char *get_file_name(char *str)
{
	int path = 0;
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '/')
			path = i + 1;
	for (int j = path; str[j] != '.' && str[j] != '\0'; j++)
		len += 1;
	for (int k = 0; k < len; k++)
		str[k] = str[path++];

	str[len] = '\0';
	return (str);
}

static char *conv_filename(char *str)
{
	char *result = malloc(sizeof(char) * (my_strlen(str) + SIZE_EXT));

	if (!result)
		return (NULL);
	str = get_file_name(str);
	result[0] = '\0';
	my_strncpy(result, str, my_strlen(str) + 1);
	my_strncat(result, ".cor", 4);
	return (result);
}

static char *open_file(char *file)
{
	int fd = open(file, O_RDONLY);
	char buff[1];
	char *str = malloc(sizeof(char));
	int size = 0;

	if (!str)
		return (NULL);
	if (fd == -1) {
		free(str);
		return (NULL);
	}
	for (int i = 1; (size = read(fd, buff, 1)) != 0; i++) {
		if (size == -1)
			return (NULL);
		str = realloc(str, i + 1);
		if (!str)
			return (NULL);
		str[i - 1] = buff[0];
		str[i] = '\0';
	}
	return (str);
}

bool compile(char *file, asm_t *asm_struct)
{
	char *str = NULL;
	char *hex = NULL;
	char *file_name = NULL;

	asm_struct->array = NULL;
	str = open_file(file);
	if (!str) {
		puterr("Error: Can't open file\n");
		return false;
	}
	asm_struct->array = conv_file(str);
	if (!asm_struct->array)
		return false;
	file_name = conv_filename(file);
	hex = conv_hex(COREWAR_EXEC_MAGIC);
	write_bytes(file_name, hex);
	free(file_name);
	free(hex);
	free(str);
	return true;
}
