/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_st
*/

#include "corewar/vm/exec_champion.h"

void exec_st(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;
	uint16_t value = 0;

	switch ((token->args_type >> (bit_shift - 2)) & mask) {
	case 1:
		champ->reg[token->arg_two - 1]
		= champ->reg[token->arg_one - 1];
		return;
	case 2: value += (int16_t) token->arg_two; break;
	case 3: value += (int16_t) token->arg_two; break;
	}
	copy_in_pc(champ->pc->pc + value % IDX_MOD, token, champ,
		champ->reg[token->arg_one - 1]);
}
