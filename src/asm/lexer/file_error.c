/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file_error.c
*/

#include "asm/lexer/file_error.h"

static bool conv_file_error_handling(asm_t *asm_struct, char *str)
{
	asm_struct->array = str_split(str, '\n');
	if (!asm_struct->array)
		return false;
	return true;
}

static char *open_file_error_handling(char *str, char *file)
{
	str = open_file(file);
	if (!str) {
		puterr(OPEN_FILE_ERROR);
		return NULL;
	}
	return str;
}

bool set_name_comment(asm_t *asm_struct, char *str)
{
	size_t beg;
	size_t end;

	if (my_strncmp(str, NAME_CMD_STRING,
	my_strlen(NAME_CMD_STRING)) == 0) {
		beg = first_index_of(str, '\"') + 1;
		end = last_index_of(str, '\"') - 1;
		if (end - beg + 1 > PROG_NAME_LENGTH)
			return false;
		asm_struct->name = substring(str, beg, end);
	} else if (my_strncmp(str, COMMENT_CMD_STRING,
	my_strlen(COMMENT_CMD_STRING)) == 0) {
		beg = first_index_of(str, '\"') + 1;
		end = last_index_of(str, '\"') - 1;
		if (end - beg + 1 > COMMENT_LENGTH)
			return false;
		asm_struct->comment = substring(str, beg, end);
	}
	return true;
}

static bool compile_struct(asm_t *asm_struct, char *str, char *file_name)
{
	bool valid_header;

	valid_header = fill_struct(asm_struct);
	if (valid_header)
		write_bytes(file_name, asm_struct);
	free(str);
	free(file_name);
	return valid_header;
}

bool compile_error_handling(char *str, asm_t *asm_struct,
				char *file_name, char *file)
{
	str = open_file_error_handling(str, file);
	if (!str)
		return false;
	if (!conv_file_error_handling(asm_struct, str) ||
	!check_labels(asm_struct)) {
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
	return compile_struct(asm_struct, str, file_name);
}
