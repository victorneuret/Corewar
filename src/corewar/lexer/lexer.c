/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** lexer
*/

#include "corewar/lexer/lexer.h"

champion_t *lexer(char *champion_path, champion_t *new)
{
	int fd = open(champion_path, O_RDONLY);

	if (fd == -1) {
		free(new);
		return NULL;
	}
	champion_lexer(new, fd);
	close(fd);
	return new;
}
