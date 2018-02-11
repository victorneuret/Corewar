/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Padding
*/

#include "my_printf.h"

static int get_first_number(char const *str)
{
	for (int i = 0; i < pf_strlen(str); i++)
		if (str[i] >= '0' && str[i] <= '9')
			return (str[i] - '0');
	return (-1);
}

void pf_init_paddings(flag_list_t *head)
{
	int isneg;
	int padding;
	flag_list_t *current = head;

	while (current) {
		padding = pf_getnbr(current->flag);
		isneg = padding < 0;
		padding = ABS(padding) - pf_strlen(current->formated);
		if (padding < 0)
			padding = 0;
		padding *= isneg ? -1 : 1;
		current->padding = padding;
		current->pad_zeros = get_first_number(current->flag) == '0';
		current = current->next;
	}
}
