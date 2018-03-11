/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** lexer for compiled asm
*/

#include "corewar/lexer/lexer_asm.h"

static bool read_header_pass(int fd)
{
	header_t header = {0};

	if (read(fd, &header, sizeof(header_t)) <= 0)
		return false;
	return true;
}

static bool read_asm(int fd, uint8_t *buffer, champion_t *new, size_t size)
{
	if (read(fd, buffer, size) <= 0)
		return false;
	new->asm_token = buffer;
	new->asm_token_len = size;
	return true;
}

bool champion_lexer(champion_t *new, int fd)
{
	uint8_t *buffer = malloc(sizeof(uint8_t) * new->header.prog_size);

	if (!read_header_pass(fd))
		return false;
	if (!read_asm(fd, buffer, new, new->header.prog_size))
		return false;
	return true;
}
