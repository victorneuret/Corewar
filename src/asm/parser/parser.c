/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File parser
*/

#include "asm/parser/parser.h"

bool check_good_parameters(int code, int nb)
{
	return (nb == (code & nb)) ? true : false;
}

static size_t find_separator(char *line, char separator)
{
	size_t len = 0;

	if (!line)
		return 0;
	for (; line[len]; len++) {
		if (line[len] == separator)
			return len;
	}
	return len;
}

static ssize_t comment_space(char *line, ssize_t comment)
{
	if (comment < 0)
		return -1;
	comment -= 1;
	for (; line[comment] != '\0' && (line[comment] == ' ' ||
	line[comment] == '\t'); comment--);
	return (comment);
}

char **parse_line(char *line)
{
	char **array = NULL;
	size_t sep = find_separator(line, ' ') - 1;
	size_t i = 0;
	ssize_t commentary = 0;

	commentary = first_index_of(line, '#');
	array = malloc(3 * (sizeof(char*)));
	if (!array)
		return NULL;
	array[i++] = substring(line, 0, sep);
	if (my_strlen(line) != (sep + 1) && (ssize_t)sep !=
	comment_space(line, commentary)) {
		if (commentary != -1)
			array[i++] = substring(line, sep + 2,
			comment_space(line, commentary));
		else
			array[i++] = substring(line, sep + 2, my_strlen(line));
	}
	array[i] = 0;
	return array;
}
