/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file_error.c
*/

#include "asm/lexer/file_error.h"

static bool conv_file_error_handling(asm_t *asm_struct, char *str)
{
	asm_struct->array = conv_file(str);
	if (!asm_struct->array)
		return false;
	return true;
}

static char *open_file_error_handling(char *str, char *file)
{
	str = open_file(file);
	if (!str) {
		puterr("Error: Can't open file\n");
		return NULL;
	}
	return str;
}

bool compile_error_handling(char *str, asm_t *asm_struct,
char *file_name, char *file)
{
	str = open_file_error_handling(str, file);
	if (!str)
		return false;
	if (!conv_file_error_handling(asm_struct, str)) {
		free(str);
		return false;
	}
	file_name = conv_filename(file);
	if (!check_syntax(asm_struct) || !file_name) {
		free(str);
		if (file_name)
			free(file_name);
		return false;
	}
	fill_struct(asm_struct);
	write_bytes(file_name, asm_struct);
	free(str);
	free(file_name);
	return true;
}
