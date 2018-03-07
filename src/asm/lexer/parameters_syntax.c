/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** parameters_syntax.c
*/

#include "asm/lexer/parameters_syntax.h"

static bool check_function_parameters(char **args, asm_t *asm_s)
{
	for (uint8_t i = 0; args[i]; i++) {
		if (args[i][0] == 'r' || args[i][0] == DIRECT_CHAR ||
		args[i][0] == LABEL_CHAR)
			return true;
	}
	syntax_error(asm_s, error_message[5]);
	return false;
}

static bool check_function_arguments(char **str, asm_t *asm_s)
{
	size_t params = op_tab[function_exists(str[0])].nbr_args;
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
	if (!check_function_parameters(args, asm_s))
		return false;
	free_str_array(args);
	return true;
}

bool function_arguments(char **str, asm_t *asm_s)
{
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
