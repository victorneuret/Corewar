/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** function_syntax.c
*/

#include "asm/lexer/function_syntax.h"

static uint8_t function_exists(char *function)
{
	for (uint8_t i = 0; op_tab[i].mnemonique; i++) {
		if (my_strncmp(function, op_tab[i].mnemonique,
			my_strlen(function)) == 0)
				return op_tab[i].code;
	}
	return 0;
}

static size_t count_args(char **str)
{
	size_t len = 0;

	for (; str[len]; len++);
	return len;
}

static bool check_function_arguments(char **str, asm_t *asm_s)
{
	size_t params = function_exists(str[0]);
	size_t nb_args = 0;
	char **args = str_split(str[1], SEPARATOR_CHAR);

	if (!args)
		return false;
	nb_args = count_args(args);
	if (nb_args > params) {
		syntax_error(asm_s, error_message[6]);
		free_str_array(args);
		return false;
	}
	else if (nb_args != params) {
		syntax_error(asm_s, error_message[5]);
		free_str_array(args);
		return false;
	}
	free_str_array(args);
	return true;
}

bool check_function(char *line, asm_t *asm_s)
{
	char **str = NULL;

	str = parse_line(line);
	if (!str)
		return false;
	if (function_exists(str[0]) == 0) {
		syntax_error(asm_s, error_message[4]);
		free_str_array(str);
		return false;
	}
	if (!str[1]) {
		syntax_error(asm_s, error_message[5]);
		free_str_array(str);
		return false;
	}
	if (!check_function_arguments(str, asm_s)) {
		free_str_array(str);
		return false;
	}
	free_str_array(str);
	return true;
}
