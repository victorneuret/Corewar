/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** aff parser
*/

#include "corewar/parser/asm_parser.h"

bool aff_parser(token_t *token, uint8_t *asm_token, int i)
{
	token_t *tmp = token;
	int pc = i;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[i];
	tmp->args_type = asm_token[i + 1];
	tmp->nb_bytes = 2;
	pc += 2;
	if (!asm_arg_register(tmp, asm_token, 0, &pc))
		return false;
	return true;
}
