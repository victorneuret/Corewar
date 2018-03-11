/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Labels writter
*/

#include "asm/writter/labels_writter.h"

void init_labels(label_t *label_s, asm_t *asm_s)
{
	for (size_t i = 0; asm_s->labels[i]; i++)
		label_s[i].label = asm_s->labels[i];
}

void insert_label_define(uint32_t *new_len, label_t *label_s)
{
	static size_t i = 0;

	label_s[i++].label_define = *new_len;
}

void insert_label_call(char *label, uint32_t call,label_t *label_s)
{
	for (size_t i = 0; label_s[i].label; i++) {
		if (my_strncmp(label, label_s[i].label,
		my_strlen(label_s[i].label)) == 0)
			label_s[i].label_call = call;
	}
}

void free_struct(label_t *label_s, size_t label_count)
{
	if (!label_s)
		return;
	for (size_t i = 0; i < label_count; i++) {
		if (!&label_s[i])
			free(&label_s[i]);
	}
	free(label_s);
}
