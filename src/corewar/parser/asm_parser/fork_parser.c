/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** fork & lfork parser
*/

#include "corewar/parser/asm_parser.h"

bool fork_parser(__attribute__((unused)) token_t *token,
	__attribute__((unused)) char *asm_token, int *i)
{
	my_printf("%s\n", "fork");
	*i += 2;
	return true;
}
