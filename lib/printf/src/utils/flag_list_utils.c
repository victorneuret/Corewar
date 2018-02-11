/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Flag list utils
*/

#include "my_printf.h"

void pf_free_list(flag_list_t *element)
{
	if (!element)
		return;
	free(element->flag);
	free(element->formated);
	if (element->next)
		pf_free_list(element->next);
	free(element);
}

void pf_rm_last_element(flag_list_t *element)
{
	if (element) {
		pf_free_list(element->next);
		element->next = 0;
	}
}
