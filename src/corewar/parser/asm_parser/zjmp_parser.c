/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** zjmp parser
*/

#include "corewar/parser/asm_parser.h"

bool zjmp_parser(token_t *token, uint8_t *asm_token, int i)
{
	token_t *tmp = token;
	int pc = i;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[i];
	tmp->args_type = 0;
	tmp->nb_bytes = 1;
	pc += 1;
	if (!asm_arg_indirect(tmp, asm_token, 0, &pc))
		return false;
	return true;
}
