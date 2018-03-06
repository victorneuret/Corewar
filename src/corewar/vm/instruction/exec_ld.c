/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_ld
*/

#include "corewar/vm/exec_champion.h"

void exec_ld(token_t *token, champion_t *champ)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;

	switch ((token->args_type >> bit_shift) & mask) {
	case 2: champ->reg[token->arg_two] = token->arg_one; break;
	case 3: champ->reg[token->arg_two] = indirect(token->arg_one, champ);
		break;
	}
}