/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** String utils
*/

#include <unistd.h>
#include <stdlib.h>

size_t my_strlen(char const *str)
{
	size_t i = 0;

	if (!str)
		return 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int str_eq(char const *str1, char const *str2)
{
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);

	if (len1 != len2)
		return 0;
	for (int i = 0; i < len1; i++)
		if (str1[i] != str2[i])
			return 0;
	return 1;
}

int my_strncmp(char const *s1, char const *s2, size_t n)
{
	char c1;
	char c2;

	for (size_t i = 0; i < n; i++) {
		c1 = s1[i];
		c2 = s2[i];
		if (c1 == '\0' || c2 == '\0' || c1 != c2)
			return c1 - c2;
	}
	return 0;
}

char *my_revstr(char *str)
{
	char temp;
	size_t index1 = 0;
	size_t index2 = my_strlen(str) - 1;

	if (!str)
		return NULL;
	while (index1 < index2) {
		temp = str[index1];
		str[index1] = str[index2];
		str[index2] = temp;
		index1++;
		index2--;
	}
	return str;
}

char *my_strncat(char *dest, char const *to_add, size_t n)
{
	size_t i;
	size_t dest_len = my_strlen(dest);

	for (i = 0; to_add[i] && i < n; i++)
		dest[dest_len + i] = to_add[i];
	dest[dest_len + i] = 0;
	return dest;
}
