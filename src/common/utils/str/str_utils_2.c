/*
** EPITECH PROJECT, 2017
** Corewar
** File description:
** String utils
*/

#include <stdlib.h>
#include <unistd.h>

#include "common/bool.h"

#include "common/utils/str/str_utils.h"

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

char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;

	for (; src[i] && i < n; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = 0;
	return dest;
}

bool ends_with(char const *str, char const *suffix)
{
	size_t src_len = my_strlen(str);
	size_t suf_len = my_strlen(suffix);

	if (suf_len > src_len)
		return false;
	if (!str)
		return false;
	return (my_strncmp(str + src_len - suf_len, suffix, suf_len)) == 0;
}
