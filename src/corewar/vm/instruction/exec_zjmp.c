/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_zjmp
*/

#include "corewar/vm/exec_champion.h"

void exec_zjmp(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	if (champ->carry == false)
		return;
	// my_printf("pc before: %d\n", champ->pc->pc);
	// if ((int8_t) token->arg_one < 0)
	// 	token->arg_one -= 1;
	// else
	// 	token->arg_one += 1;
	champ->pc->pc = (champ->pc->pc + (int16_t) token->arg_one % IDX_MOD
			- token->nb_bytes) % MEM_SIZE;
	// my_printf("arg_one: %#x\t%d\n", (int16_t) token->arg_one,
	// 				(int16_t) token->arg_one);
	// my_printf("pc after: %d\n", champ->pc->pc);
	// my_printf("mem pc: %#x %#x %#x %#x %#x\n", vm->memory[champ->pc->pc], vm->memory[champ->pc->pc + 1], vm->memory[champ->pc->pc + 2], vm->memory[champ->pc->pc + 3], vm->memory[champ->pc->pc + 4]);
}
