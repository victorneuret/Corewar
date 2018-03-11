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

static bool compare_labels(asm_t *asm_s, int i)
{
	for (size_t j = i + 1; asm_s->labels[j] != NULL; j++) {
		if (str_eq(asm_s->labels[i], asm_s->labels[j])) {
			syntax_error(asm_s, error_message[7]);
			free_str_array(asm_s->labels);
			return false;
		}
	}
	return true;
}

static bool check_labels(asm_t *asm_s)
{
	asm_s->labels = get_label_list(asm_s->array);
	if (!asm_s->labels)
		return false;
	for (size_t i = 0; asm_s->labels[i] != NULL; i++) {
		if (!compare_labels(asm_s, i))
			return false;
	}
	free_str_array(asm_s->labels);
	return true;
}

bool check_function(char *line, asm_t *asm_s)
{
	char **str = NULL;

	str = parse_line(line);
	if (!str)
		return false;
	if (function_exists(str[0]) == -1) {
		if (str[0][my_strlen(str[0]) - 1] == LABEL_CHAR && !str[1]) {
			free_str_array(str);
			return true;
		}
		syntax_error(asm_s, error_message[4]);
		free_str_array(str);
		return false;
	}
	if (!function_arguments(str, asm_s) || !check_labels(asm_s)) {
		free_str_array(str);
		return false;
	}
	free_str_array(str);
	return true;
}
