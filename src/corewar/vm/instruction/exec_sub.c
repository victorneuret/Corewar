/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_add
*/

#include "corewar/vm/exec_champion.h"

void exec_sub(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	champ->reg[token->arg_three - 1] = champ->reg[token->arg_one - 1]
					- champ->reg[token->arg_two - 1];
}
