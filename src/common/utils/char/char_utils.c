/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Char utils
*/

#include <stdlib.h>

ssize_t first_index_of(char const *str, char const c)
{
	if (!str)
		return -1;
	for (ssize_t i = 0; str[i]; i++)
		if (str[i] == c)
			return i;
	return -1;
}

ssize_t last_index_of(char const *str, char const c)
{
	ssize_t index = -1;

	if (!str)
		return -1;
	for (ssize_t i = 0; str[i]; i++)
		if (str[i] == c)
			index = i;
	return index;
}
