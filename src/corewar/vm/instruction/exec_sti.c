/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_sti
*/

#include "corewar/vm/exec_champion.h"

void exec_sti(token_t *token, champion_t *champ, vm_core_t *vm)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;
	uint16_t value = 0;

	switch ((token->args_type >> (bit_shift - 2)) & mask) {
	case 1: value += champ->reg[token->arg_two - 1]; break;
	case 2: value += (int16_t) token->arg_two; break;
	case 3: value += (int16_t) token->arg_two; break;
	}
	switch ((token->args_type >> (bit_shift - 4)) & mask) {
	case 1: value += champ->reg[token->arg_three - 1]; break;
	case 2: value += (int16_t) token->arg_three; break;
	}
	vm->memory[(champ->pc->pc + 3 + value % IDX_MOD) % MEM_SIZE]
	= champ->reg[token->arg_one - 1];
}
