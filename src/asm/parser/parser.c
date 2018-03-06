/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File parser
*/

#include "asm/parser/parser.h"

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

char **parse_line(char *line)
{
	char **array = malloc(3 * (sizeof(char*)));
	size_t sep = find_separator(line, ' ') - 1;
	int i = 0;

	array[i++] = substring(line, 0, sep);
	if (my_strlen(line) != (sep + 1))
		array[i++] = substring(line, sep + 2, my_strlen(line));
	array[i] = 0;
	return array;
}
