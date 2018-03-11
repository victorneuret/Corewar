/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** parameters_syntax.c
*/

#include "asm/lexer/parameters_syntax.h"

static bool check_function_parameters(char **args, uint8_t func, asm_t *asm_s)
{
	uint8_t nb = 0;
	size_t j = 0;

	for (uint8_t i = 0; args[i]; i++) {
		for (j = 0; (args[i][j] == ' ' || args[i][j] == '\t') &&
		args[i][j] != '\0'; j++);
		nb = check_arguments_types(args[i], j, asm_s);
		if (nb == 0)
			return false;
		if (!check_good_parameters(op_tab[func].type[i], nb)) {
			syntax_error(asm_s, error_message[5]);
			return false;
		}
	}
	return true;
}

static bool check_function_arguments_error(size_t nb_args, asm_t *asm_s,
size_t params, char **args)
{
	nb_args = count_args(args);
	if (nb_args > params) {
		syntax_error(asm_s, error_message[6]);
		return false;
	}
	else if (nb_args != params) {
		syntax_error(asm_s, error_message[5]);
		return false;
	}
	return true;
}

static bool check_function_arguments(char **str, asm_t *asm_s)
{
	size_t params = op_tab[function_exists(str[0])].nbr_args;
	size_t nb_args = 0;
	char **args = str_split(str[1], SEPARATOR_CHAR);

	if (!args)
		return false;
	if (!check_function_arguments_error(nb_args, asm_s, params, args)) {
		free_str_array(args);
		return false;
	}
	if (!check_function_parameters(args, function_exists(str[0]), asm_s)) {
		free_str_array(args);
		return false;
	}
	free_str_array(args);
	return true;
}

bool function_arguments(char **str, asm_t *asm_s)
{
	if (!str)
		return false;
	if (!str[1]) {
		syntax_error(asm_s, error_message[5]);
		return false;
	}
	if (!check_function_arguments(str, asm_s))
		return false;
	return true;
}
