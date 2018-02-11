/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Numbers
*/

#include "my_printf.h"

static void recursive_print_nb(int nb, char *result, int *index)
{
	if (nb >= 10 || nb <= -10)
		recursive_print_nb(nb / 10, result, index);
	result[*index] = (ABS(nb) % 10 + 48);
	*index = *index + 1;
}

static int get_nb_len(int nb)
{
	int length = 0;

	if (nb < 0)
		length++;
	if (nb == 0)
		return (1);
	while (nb != 0) {
		nb /= 10;
		length++;
	}
	return (length);
}

char *nbr_to_str(int nb)
{
	int index = 0;
	int length = get_nb_len(nb);
	char *result = pf_malloc(length + 1, '\0');

	if (nb < 0)
		result[index++] = '-';
	if (nb == 0)
		result[index++] = '0';
	else
		recursive_print_nb(nb, result, &index);
	result[length] = 0;
	return (result);
}
