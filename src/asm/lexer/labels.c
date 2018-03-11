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
