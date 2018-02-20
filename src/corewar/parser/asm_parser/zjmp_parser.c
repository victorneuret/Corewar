/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** zjmp parser
*/

#include "corewar/parser/asm_parser.h"

bool zjmp_parser(__attribute__((unused)) token_t *token,
	__attribute__((unused)) char *asm_token, int *i)
{
	my_printf("%s\n", "zjmp");
	*i += 2;
	return true;
}
