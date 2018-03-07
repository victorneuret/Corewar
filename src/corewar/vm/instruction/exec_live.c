/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_live
*/

#include "corewar/vm/exec_champion.h"

void exec_live(token_t *token, champion_t *champ)
{
	my_printf("The player %d(%s) is alive.\n", token->arg_one,
		champ->header.prog_name);
	champ->live = true;
}
