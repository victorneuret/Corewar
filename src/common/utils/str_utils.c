/*
** EPITECH PROJECT, 2017
** Corewar
** File description:
** String utils
*/

#include <unistd.h>

size_t my_strlen(char const *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return i;
}

void putstr(char const *str)
{
	write(1, str, my_strlen(str));
}

void puterr(char const *str)
{
	write(2, str, my_strlen(str));
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
