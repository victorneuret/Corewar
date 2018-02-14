/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** lexer for compiled asm
*/

#include "corewar/lexer/lexer_asm.h"

bool champion_lexer(champion_t *new, int fd)
{
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	str[0] = '\0';
	read_size = read(fd, buffer, 1);
	if (read_size == -1)
		return false;
	while (read_size != 0) {
		str = check_letter_add(buffer[0], str);
		read_size = read(fd, buffer, 1);
		if (read_size == -1)
			return false;
	}
	new->asm_token = str;
	return true;
	return true;
}
