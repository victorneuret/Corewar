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
	champ->pc->pc = (champ->pc->pc + (int16_t) token->arg_one % IDX_MOD
			- token->nb_bytes) % MEM_SIZE;
}
