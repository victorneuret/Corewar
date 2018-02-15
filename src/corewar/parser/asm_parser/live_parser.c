/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** live parser
*/

#include "corewar/parser/asm_parser.h"

bool live_parser(__attribute__((unused)) token_t *token,
	__attribute__((unused)) char *asm_token, int *i)
{
	printf("%s\n", "live");
	*i += 4;
	return true;
}
