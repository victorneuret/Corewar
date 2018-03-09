/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_ldi
*/

#include "corewar/vm/exec_champion.h"

void exec_ldi(token_t *token, champion_t *champ, vm_core_t *vm)
{
	uint16_t sum = vm->memory[
			(champ->pc->pc + 1 + token->arg_one % IDX_MOD) % MEM_SIZE]
			+ token->arg_two;

	champ->reg[token->arg_three - 1] =
		vm->memory[champ->pc->pc + 1 + sum % IDX_MOD];
	if (sum == 0)
		champ->carry = true;
	champ->carry = false;

}
