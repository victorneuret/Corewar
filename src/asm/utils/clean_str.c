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
	size_t j = 0;
	char *old = str;

	for (size_t i = 0; old[i] != '\0'; i++)
		if (old[i] == '\t')
			old[i] = ' ';
	for (i = 0; old[i] == ' '; i++);
	for (i = i; old[i] != '\0'; i++) {
		if (old[i] == ' ' && (str[j - 1] == '\n'|| old[i + 1] == ' '
		|| old[i + 1] == '\0'))
			continue;
		else if (old[i] == ' ' && old[i + 1] != '\0')
			str[j++] = ' ';
		else
			str[j++] = old[i];
	}
	str[j] = '\0';
	return str;
}
