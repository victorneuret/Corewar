/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Labels writter
*/

#include "asm/writter/labels_writter.h"
#include "asm/utils/clean_str.h"

void init_labels(label_t *label_s, asm_t *asm_s)
{
	size_t i = 0;

	for (; asm_s->labels[i] != NULL; i++) {
		label_s[i].label = asm_s->labels[i];
		label_s[i].label_call = malloc(sizeof(uint16_t));
		label_s[i].offset = malloc(sizeof(uint16_t));
		label_s[i].label_call[0] = 0;
		label_s[i].label_define = 0;
		label_s[i].calls = 0;
	}
	label_s[i].label = NULL;
}

void insert_label_define(uint32_t *new_len, label_t *label_s)
{
	static size_t i = 0;

	label_s[i++].label_define = new_len[0];
}

void insert_label_call(bool byte, char *label, uint32_t *call,
label_t *label_s)
{
	static int count = 1;

	label = clean_str(label);
	label = substring(label, 2, my_strlen(label));
	if (!label)
		return;
	for (size_t i = 0; label_s[i].label; i++) {
		if (str_eq(label, label_s[i].label) == 1) {
			label_s[i].label_call = realloc(label_s[i].label_call,
			sizeof(uint16_t*) * count);
			label_s[i].offset = realloc(label_s[i].offset,
			sizeof(uint16_t*) * count);
			label_s[i].label_call[label_s[i].calls] = call[0];
			label_s[i].offset[label_s[i].calls] = call[1];
			label_s[i].calls += 1;
			label_s[i].bytes = byte;
			count++;
		}
	}
	free(label);
}

void free_struct(label_t *label_s, size_t label_count)
{
	if (!label_s)
		return;
	for (size_t i = 0; i < label_count; i++) {
		if (label_s[i].label_call)
			free(label_s[i].label_call);
		if (label_s[i].offset)
			free(label_s[i].offset);
	}
	free(label_s);
}
