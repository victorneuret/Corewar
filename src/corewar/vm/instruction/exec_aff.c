/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_aff
*/

#include "corewar/vm/exec_champion.h"

void exec_aff(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	char c = champ->reg[token->arg_one - 1] % 256;

	write(1, &c, 1);
}
