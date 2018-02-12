/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Get numbers in a certain base
*/

#include <stdio.h>
#include <stdlib.h>

#include "common/utils/str_utils.h"

static void recursive_append_nb(size_t nb, char const *base,
				char *result, size_t *index)
{
	size_t base_len = my_strlen(base);

	if (nb >= base_len)
		recursive_append_nb(nb / base_len, base, result, index);
	result[*index] = base[nb % base_len];
	*index += 1;
}

static size_t calc_len(size_t nb, size_t base_len)
{
	size_t len = 0;

	if (nb == 0)
		return 1;
	while (nb != 0) {
		nb /= base_len;
		len++;
	}
	return len;
}

char *conv_nb_base(size_t nb, char const *base)
{
	size_t base_len = my_strlen(base);
	size_t result_len = calc_len(nb, base_len);
	char *result = malloc(result_len + 1);
	size_t index = 0;

	if (!result)
		return 0;
	for (size_t i = 0; i <= result_len; i++)
		result[i] = 0;
	recursive_append_nb(nb, base, result, &index);
	return result;
}
