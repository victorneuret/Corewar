/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Labels writter
*/

#include "asm/writter/labels_writter.h"

void init_labels(label_t *label_s, asm_t *asm_s)
{
	size_t i = 0;

	for (; asm_s->labels[i] != NULL; i++) {
		label_s[i].label = asm_s->labels[i];
		label_s[i].label_call = malloc(sizeof(uint16_t));
		label_s[i].label_call[0] = 0;
		label_s[i].label_define = 0;
		label_s[i].offset = 0;
		label_s[i].calls = 0;
	}
	label_s[i].label = NULL;
}

void insert_label_define(uint32_t *new_len, label_t *label_s)
{
	static size_t i = 0;

	label_s[i++].label_define = *new_len;
}

void insert_label_call(bool byte, char *label, uint32_t call,
label_t *label_s)
{
	label = substring(label, 2, my_strlen(label));
	if (!label)
		return;
	for (size_t i = 0; label_s[i].label; i++) {
		if (my_strncmp(label, label_s[i].label,
		my_strlen(label)) == 0) {
			label_s[i].label_call = realloc(label_s[i].label_call,
			sizeof(size_t));
			label_s[i].label_call[label_s[i].calls] = call;
			label_s[i].calls += 1;
			label_s[i].offset = 0;
			label_s[i].bytes = byte;
		}
	}
	free(label);
}

void free_struct(label_t *label_s, size_t label_count)
{
	if (!label_s)
		return;
	for (size_t i = 0; i < label_count; i++)
		if (label_s[i].label_call)
			free(label_s[i].label_call);
	free(label_s);
}
