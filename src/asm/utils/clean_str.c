/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** clean_str.c
*/

#include "asm/utils/clean_str.h"

char *clean_str(char *str)
{
	size_t i = 0;
	char *line = NULL;

	for (i = 0; str[i] != '\0' &&
	(str[i] == ' ' || str[i] == '\t'); i++);
	line = substring(str, i, my_strlen(str));
	if (!line)
		return NULL;
	return line;
}
