/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_lld
*/

#include "corewar/vm/exec_champion.h"

void exec_lld(token_t *token, champion_t *champ, vm_core_t *vm)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;

	if (((token->args_type >> bit_shift) & mask) == 3)
		token->arg_one += 3;
	champ->reg[token->arg_two - 1] =
		vm->memory[champ->pc->pc + token->arg_one];
	if (champ->reg[token->arg_two - 1] == 0)
		champ->carry = true;
	else
		champ->carry = false;
}
