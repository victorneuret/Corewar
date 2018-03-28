/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Array utils
*/

#include "common/utils/nbr/getnbr.h"
#include "common/utils/str/str_utils.h"

int get_or_default(char **arr, char *key)
{
	size_t key_len = my_strlen(key);

	for (size_t i = 0; arr && arr[i]; i++)
		if (my_strncmp(arr[i], key, key_len) == 0)
			return getnbr(arr[++i]);
	return -1;
}
