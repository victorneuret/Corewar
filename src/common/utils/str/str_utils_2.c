/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** String utils
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "common/utils/str/str_utils.h"

bool is_number(char const *str)
{
	size_t i = 0;

	if (!str || my_strlen(str) == 0)
		return false;
	if (str[i] == '-')
		i++;
	for (; i < my_strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		return false;
	}
	return true;
}

char *my_strdup(char const *src)
{
	char *dest;
	size_t length = my_strlen(src);

	dest = malloc(sizeof(char) * (length + 1));
	if (!dest)
		return NULL;
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
	if (!str || !suffix)
		return false;
	return (my_strncmp(str + src_len - suf_len, suffix, suf_len)) == 0;
}

char *substring(char const *src, size_t begin, size_t end)
{
	char *result = malloc(end - begin + 2);

	if (!result)
		return NULL;
	for (size_t i = 0; i < end - begin + 1; i++)
		result[i] = src[begin + i];
	result[end - begin + 1] = 0;
	return result;
}
