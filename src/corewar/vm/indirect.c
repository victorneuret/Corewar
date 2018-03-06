/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** indirect
*/

#include "corewar/vm/exec_champion.h"

uint32_t indirect(int ind, champion_t *champ)
{
	uint32_t value = champ->asm_token[champ->pc->pc + ind + 1 % IDX_MOD];

	return value;
}
