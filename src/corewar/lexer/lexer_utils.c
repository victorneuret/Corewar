/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** lexer_utils
*/

#include "corewar/lexer/lexer_utils.h"

static char *add_string(char const c, char *str)
{
	char *ptr;

	if (str[0] == '\0') {
		str[0] = c;
		str[1] = '\0';
		return str;
	}
	ptr = malloc(sizeof(char) * (my_strlen(str) + 2));
	if (!ptr)
		return NULL;
	for (unsigned int i = 0; i < my_strlen(str) + 2; i++)
		ptr[i] = '\0';
	for (int i = 0; str[i] != '\0'; i++) {
		ptr[i] = str[i];
		ptr[i + 1] = c;
	}
	free(str);
	return ptr;
}

char *check_letter_add(char const c, char *str)
{
	if (c >= 20 && c <= 126)
		str = add_string(c, str);
	if (!str)
		return NULL;
	return str;
}
