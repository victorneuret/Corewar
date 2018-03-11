/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** is_label.c
*/

#include "asm/utils/is_label.h"

bool is_label(char const *str)
{
	size_t i = 0;

	for (i = 0; str[i] != '\0' &&
		(str[i] == ' ' || str[i] == '\t'); i++);
	if (!str[i])
		return false;
	if (str[i] == '%' && str[i + 1] == ':')
		return true;
	else if (str[my_strlen(str) - 1] == ':')
		return true;
	return false;
}
