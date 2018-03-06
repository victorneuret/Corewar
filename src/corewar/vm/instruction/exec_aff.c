/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_aff
*/

#include "corewar/vm/exec_champion.h"

void exec_aff(token_t *token, champion_t *champ)
{
	char c = champ->reg[token->arg_one] % 256;

	if (c == 0)
		return;
	write(1, &c, 1);
}
