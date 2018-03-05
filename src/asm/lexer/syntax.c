/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** syntax.c
*/

#include "asm/lexer/syntax.h"

static int count_word_array(char **str)
{
	int len = 0;

	for (; str[len] != NULL; len++);
	return (len);
}

static bool compare_line(char *line, char *string, int i)
{
	char **str = NULL;
	int count = 0;

	str = str_split(line, ' ');
	if (!line || !str || !string)
		return (false);
	count = count_word_array(str);
	if (my_strncmp(str[0], string, my_strlen(str[0])) == 0) {
		if (count == 2)
			my_printf("Line: %d %s\n", i, string);
		else {
			my_printf("Line: %d %s no argument\n", i, string);
			return (false);
		}
	} else {
		my_printf("%s not at correct line\n", string);
		return (false);
	}
	free_str_array(str);
	return (true);
}

static bool line_syntax(char *line, int i)
{
	static uint8_t nb = 0;

	if (nb == 0)
		compare_line(line, NAME_CMD_STRING, i);
	else if (nb == 1)
		compare_line(line, COMMENT_CMD_STRING, i);
	else
		my_printf("Line: %d function\n", i);
	if (nb < 2)
		nb++;
	return (true);
}

bool check_syntax(asm_t *asm_s)
{
	int i = 0;

	for (; asm_s->array[i] != NULL; i++) {
		if (my_strlen(asm_s->array[i]) == 0 ||
				asm_s->array[i][0] == COMMENT_CHAR)
			my_printf("Line: %d #\n", i);
		else
			line_syntax(asm_s->array[i], i);
	}
	return (true);
}
