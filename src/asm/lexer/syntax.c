/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** syntax.c
*/

#include "asm/lexer/syntax.h"

const char *opt_strings[] = {
	NAME_CMD_STRING,
	COMMENT_CMD_STRING,
	0
};

const char *error_message[] = {
	BLUE "No name specified.",
	BLUE "No comment specified.",
	BLUE "The comment must be just after the name.",
	BLUE "Syntax error.",
	BLUE "Invalid instruction.",
	0
};

static void syntax_error(asm_t *asm_s, const char *message)
{
	char **array = 0;

	array = str_split(asm_s->executable, '/');
	puterr(WHITE);
	puterr(array[2]);
	puterr(", ");
	puterr(asm_s->filename);
	puterr(", line ");
	puterr(int_to_char(asm_s->line));
	puterr(": ");
	puterr(message);
	puterr(NC "\n");
	free_str_array(array);
}

static bool check_comments(char *line, const char *string,
			const int nb, asm_t *asm_s)
{
	char **str = NULL;

	str = parse_comment(line);
	if (!line || !str || !string)
		return false;
	if (my_strncmp(str[0], string, my_strlen(str[0])) == 0) {
		if (!str[1]) {
			syntax_error(asm_s, error_message[nb]);
			return false;
		} else if (str[1][0] != '\"' ||
		str[1][my_strlen(str[1]) - 1] != '\"') {
			syntax_error(asm_s, error_message[3]);
			return false;
		}
	} else {
		syntax_error(asm_s, error_message[nb]);
		return false;
	}
	free_str_array(str);
	return true;
}

static bool line_syntax(char *line, asm_t *asm_s)
{
	static uint8_t nb = 0;

	if (nb < 2) {
		if (!check_comments(line, opt_strings[nb], nb, asm_s))
			return false;
		nb++;
	}
	return (true);
}

bool check_syntax(asm_t *asm_s)
{
	int i = 0;

	asm_s->line = 0;
	for (; asm_s->array[i] != NULL; i++) {
		if (my_strlen(asm_s->array[i]) == 0 ||
			asm_s->array[i][0] == COMMENT_CHAR)
				continue;
		asm_s->line = i + 1;
		if (!line_syntax(asm_s->array[i], asm_s))
			return false;
	}
	return (true);
}
