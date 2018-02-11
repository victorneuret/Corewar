/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Utility functions
*/

#include "my_printf.h"

int pf_strlen(char const *str)
{
	int offset = 0;

	while (*(str + offset))
		offset++;
	return (offset);
}

char *pf_strdup(char const *src)
{
	char *dest;
	int length = pf_strlen(src);

	dest = pf_malloc(length + 1, '\0');
	for (int i = 0; i <= length; i++)
		dest[i] = src[i];
	return (dest);
}

char *pf_substring(char const *from, int begin, int end)
{
	char *result = pf_malloc(end - begin + 2, '\0');

	for (int i = 0; i < end - begin + 1; i++)
		result[i] = from[begin + i];
	result[end - begin + 1] = 0;
	return (result);
}

char *pf_strupcase(char *str)
{
	if (str == 0)
		return (0);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}
