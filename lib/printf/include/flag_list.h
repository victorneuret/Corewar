/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Flag list header
*/

#pragma once

struct flag_list {
	int padding;
	int pad_zeros;
	char *flag;
	char *formated;
	struct flag_list *next;
};

typedef struct flag_list flag_list_t;

void pf_free_list(flag_list_t *element);
void pf_rm_last_element(flag_list_t *element);
