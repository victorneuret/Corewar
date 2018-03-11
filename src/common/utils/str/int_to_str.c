/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Int to string
*/

#include <stdlib.h>

#include "common/macros.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/nbr/get_nb_len.h"

static void recursive_append_nb(int nb, char *result, int *index)
{
	if (nb >= 10 || nb <= -10)
		recursive_append_nb(nb / 10, result, index);
	result[*index] = (ABS(nb) % 10 + '0');
	*index = *index + 1;
}

char *int_to_str(int nb)
{
	int index = 0;
	int length = get_nb_len(nb);
	char *result = malloc(length + 1);

	if (!result)
		return NULL;
	if (nb < 0)
		result[index++] = '-';
	if (nb == 0)
		result[index++] = '0';
	else
		recursive_append_nb(nb, result, &index);
	result[length] = 0;
	return result;
}
