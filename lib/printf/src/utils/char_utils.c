/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Char utils
*/

#include "my_printf.h"

char pf_last_char(char const *str)
{
	int last_index = pf_strlen(str) - 1;

	return (str[last_index]);
}

int pf_contains_specifiers(char const *str)
{
	for (int i = 0; i < pf_strlen(str); i++)
		if (str[i] == '%')
			return (1);
	return (0);
}

int pf_is_specifier(char c)
{
	char specifiers[] = "disScXxoup0123456789+-#*";

	for (int i = 0; i < pf_strlen(specifiers); i++)
		if (c == specifiers[i])
			return (1);
	return (0);
}

int pf_is_flag_end(char c)
{
	return c != ' ' && c != '%' && c != 0;
}
