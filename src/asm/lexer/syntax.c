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
	BLUE "The argument given to the instruction is invalid.",
	BLUE "Too many arguments given to the instruction.",
	BLUE "Multiple definition of the same label.",
	BLUE "Invalid register number.",
	0
};

void syntax_error(asm_t *asm_s, const char *message)
{
	char **array = 0;
	char *str = NULL;

	array = str_split(asm_s->executable, '/');
	str = int_to_str(asm_s->line);
	if (!str || !array)
		return;
	puterr(WHITE);
	puterr(array[2]);
	puterr(", ");
	puterr(asm_s->filename);
	puterr(", line ");
	puterr(str);
	puterr(": ");
	puterr(message);
	puterr(NC "\n");
	free_str_array(array);
	free(str);
}

static bool error_type(char **str, char const *string,
			const int nb, asm_t *asm_s)
{
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
		if (nb == 0 && my_strncmp(str[0], COMMENT_CMD_STRING,
		my_strlen(str[0])) == 0)
			syntax_error(asm_s, error_message[2]);
		else
			syntax_error(asm_s, error_message[nb]);
		return false;
	}
	return true;
}

static bool check_comments(char *line, const char *string,
const int nb, asm_t *asm_s)
{
	char **str = NULL;

	str = parse_line(line);
	if (!line || !str || !string || !error_type(str, string, nb, asm_s))
		return false;
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
	} else if (!check_function(line, asm_s))
		return false;
	return true;
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
