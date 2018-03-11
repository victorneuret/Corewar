/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** function_syntax.c
*/

#include "asm/lexer/function_syntax.h"

int function_exists(char *function)
{
	for (int i = 0; op_tab[i].mnemonique; i++) {
		if (my_strncmp(function, op_tab[i].mnemonique,
			my_strlen(function)) == 0)
				return i;
	}
	return -1;
}

size_t count_args(char **str)
{
	size_t len = 0;

	for (; str[len]; len++);
	return len;
}

bool check_function(char *line, asm_t *asm_s)
{
	char **str = parse_line(line);

	if (!str)
		return false;
	if (function_exists(str[0]) == -1) {
		if (!check_label_line(str, asm_s)) {
			free_str_array(str);
			return false;
		}
		free_str_array(str);
		return true;
	}
	if (!function_arguments(str, asm_s)) {
		free_str_array(str);
		return false;
	}
	free_str_array(str);
	return true;
}
