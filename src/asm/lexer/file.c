/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file.c
*/

#include "asm/lexer/file.h"

static char *get_file_name(char *str)
{
	uint8_t path = 0;
	uint8_t len = 0;

	for (uint8_t i = 0; str[i] != '\0'; i++)
		if (str[i] == '/')
			path = i + 1;
	for (uint8_t j = path; str[j] != '.' && str[j] != '\0'; j++)
		len += 1;
	for (uint8_t k = 0; k < len; k++)
		str[k] = str[path++];
	str[len] = '\0';
	return (str);
}

char *conv_filename(char *str)
{
	char *result = malloc(sizeof(char) * (my_strlen(str) + SIZE_EXT));

	if (!result)
		return (NULL);
	str = get_file_name(str);
	result[0] = '\0';
	my_strncpy(result, str, my_strlen(str) + 1);
	my_strncat(result, BINARY_EXTENSION, 4);
	return (result);
}

char *open_file(char *file)
{
	int fd = open(file, O_RDONLY);
	char buff[1];
	char *str = malloc(sizeof(char));
	int size = 0;

	if (!str || fd == -1) {
		if (str)
			free(str);
		return (NULL);
	}
	for (size_t i = 1; (size = read(fd, buff, 1)) != 0; i++) {
		if (size == -1)
			return (NULL);
		str = realloc(str, i + 1);
		if (!str)
			return (NULL);
		str[i - 1] = buff[0];
		str[i] = '\0';
	}
	str = clean_str(str);
	return (str);
}

bool fill_struct(asm_t *asm_struct)
{
	for (size_t i = 0; asm_struct->array[i]; i++) {
		if (!set_name_comment(asm_struct, asm_struct->array[i])) {
			puterr("Name or comment too long.\n");
			return false;
		}
	}
	return true;
}

bool compile(char *file, asm_t *asm_struct)
{
	char *str = NULL;
	char *file_name = NULL;

	asm_struct->labels = NULL;
	if (!compile_error_handling(str, asm_struct, file_name, file))
		return false;
	return true;
}
