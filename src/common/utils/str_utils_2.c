/*
** EPITECH PROJECT, 2017
** Corewar
** File description:
** String utils
*/

#include <stdlib.h>
#include <unistd.h>

#include "common/utils/str_utils.h"

char *my_strdup(char const *src)
{
	char *dest;
	size_t length = my_strlen(src);

	dest = malloc(sizeof(char) * (length + 1));
	if (!dest)
		return 0;
	for (size_t i = 0; src && i <= length; i++)
		dest[i] = src[i];
	return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;

	for (i = 0; src[i] && i < n; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = 0;
	return dest;
}
