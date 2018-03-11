/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** labels.c
*/

#include "asm/lexer/labels.h"

static bool compare_labels(asm_t *asm_s, int i)
{
	for (size_t j = i + 1; asm_s->labels[j] != NULL; j++) {
		if (str_eq(asm_s->labels[i], asm_s->labels[j]) == 1) {
			syntax_error(asm_s, error_message[7]);
			free_str_array(asm_s->labels);
			return false;
		}
	}
	return true;
}

bool check_labels(asm_t *asm_s)
{
	asm_s->labels = get_label_list(asm_s->array);
	if (!asm_s->labels)
		return false;
	for (size_t i = 0; asm_s->labels[i] != NULL; i++) {
		if (!compare_labels(asm_s, i))
			return false;
	}
	return true;
}

static bool check_label_line_function(char **array, asm_t *asm_s)
{
	if (function_exists(array[0]) != -1) {
		if (!function_arguments(array, asm_s))
			return false;
	}
	return true;
}

static bool label_line_error(char **str, char ***array, asm_t *asm_s)
{
	char *line = NULL;

	if (str[1] != NULL) {
		line = clean_str(str[1]);
		if (!line)
			return false;
		*array = parse_line(line);
		free(line);
		if (!*array)
			return false;
		if (!check_label_line_function(*array, asm_s))
			return false;
	}
	return true;
}

bool check_label_line(char **str, asm_t *asm_s)
{
	char **array = NULL;

	if (str[0][my_strlen(str[0]) - 1] == LABEL_CHAR) {
		if (!label_line_error(str, &array, asm_s)) {
			free_str_array(array);
			return false;
		}
		free_str_array(array);
		return true;
	}
	syntax_error(asm_s, error_message[4]);
	return false;
}
