/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_lldi
*/

#include "corewar/vm/exec_champion.h"

void exec_lldi(token_t *token, champion_t *champ, vm_core_t *vm)
{
	uint16_t one = is_reg(1, token->args_type) ?
			champ->reg[token->arg_one - 1] :
			(uint16_t) (token->arg_one + 1);
	uint16_t two = is_reg(2, token->args_type) ?
			champ->reg[token->arg_two - 1] :
			(uint16_t) (token->arg_two);
	uint16_t sum = vm->memory[(champ->pc->pc + one)
				% MEM_SIZE] + two;

	champ->reg[token->arg_three - 1] = vm->memory[champ->pc->pc +
			(is_reg(1, token->args_type) ? 0 : 1) + sum];
	if (sum == 0)
		champ->carry = true;
	champ->carry = false;
}
