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
	printf("File : %s\n", str);
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

char *open_file(char *file)
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

int write_file(char *file, char *str)
{
	int fd = open(file, O_RDWR | O_CREAT, 0666);

	if (file == NULL)
		return (84);
	else if (fd == -1)
		return 84;
	for (int i = 0; str[i] != '\0'; i++)
		write(fd, &str[i], 1);
	return (0);
}

int file_handling(char *file, asm_t *asm_struct)
{
	char *str = NULL;
	asm_struct->array = NULL;

	str = open_file(file);
	if (!str) {
		puterr("Error: Can't open file\n");
		return (84);
	}
	asm_struct->array = conv_file(str);
	if (!asm_struct->array)
		return (84);
	if (write_file(conv_filename(file), str) == 84)
		return (84);
	free(str);
	return (0);
}
