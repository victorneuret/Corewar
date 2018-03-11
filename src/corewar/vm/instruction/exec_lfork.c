/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_lfork
*/

#include "corewar/vm/exec_champion.h"

void exec_lfork(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	champ = add_champ_fork(champ, (uint16_t) token->arg_one);
	if (!champ)
		return;
}
