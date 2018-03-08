/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_ld
*/

#include "corewar/vm/exec_champion.h"

void exec_ld(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;

	switch ((token->args_type >> bit_shift) & mask) {
	case 2: champ->reg[token->arg_two - 1] = token->arg_one; break;
	case 3: champ->reg[token->arg_two - 1] = indirect(token->arg_one,
							champ);
		break;
	}
	if (champ->reg[token->arg_two - 1] == 0)
		champ->carry = true;
	else
		champ->carry = false;
}
