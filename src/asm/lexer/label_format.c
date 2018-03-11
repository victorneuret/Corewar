/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** label_format
*/

#include "asm/lexer/labels.h"

static bool is_valid_char(char const c)
{
	char *valid_chars = LABEL_CHARS;

	for (size_t i = 0; i < my_strlen(valid_chars); i++)
		if (valid_chars[i] == c)
			return true;
	return false;
}

bool is_valid_label_name(char const *line)
{
	for (size_t i = 0; i < my_strlen(line); i++)
		if (!is_valid_char(line[i]))
			return false;
	return true;
}
