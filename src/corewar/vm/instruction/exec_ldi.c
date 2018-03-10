/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_ldi
*/

#include "corewar/vm/exec_champion.h"

static bool is_reg(uint8_t nb, uint8_t arg)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;

	if (nb == 2)
		bit_shift -= 2;
	else if (nb == 3)
		bit_shift -= 4;
	switch ((arg >> (bit_shift)) & mask) {
	case 1: return true;
	default: return false;
	}
	return false;
}

void exec_ldi(token_t *token, champion_t *champ, vm_core_t *vm)
{
	uint16_t one = is_reg(1, token->args_type) ?
			champ->reg[token->arg_one - 1] :
			(uint16_t) (token->arg_one + 1);
	uint16_t two = is_reg(2, token->args_type) ?
			champ->reg[token->arg_two - 1] :
			(uint16_t) (token->arg_two);
	uint16_t sum = vm->memory[(champ->pc->pc + one % IDX_MOD)
				% MEM_SIZE] + two;

	champ->reg[token->arg_three - 1] = vm->memory[champ->pc->pc +
			(is_reg(1, token->args_type) ? 0 : 1) + sum % IDX_MOD];
	if (sum == 0)
		champ->carry = true;
	champ->carry = false;
}
