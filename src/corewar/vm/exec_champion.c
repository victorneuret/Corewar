/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_champion
*/

#include "corewar/vm/exec_champion.h"

static exec_instruction_t instru[] = {
	{1, &nope},
	{2, &exec_ld},
	{3, &nope},
	{4, &nope},
	{5, &nope},
	{6, &nope},
	{7, &nope},
	{8, &nope},
	{9, &nope},
	{10, &nope},
	{11, &nope},
	{12, &nope},
	{13, &nope},
	{14, &nope},
	{15, &nope},
	{16, &exec_aff},
	{0, NULL}
};

void nope(__attribute__((unused)) token_t *token,
	__attribute__((unused)) champion_t *champ)
{
	return;
}

static bool exec_instruction(token_t *cmd, champion_t *champ)
{
	for (int i = 0; instru[i].id; i++) {
		if (cmd->command == instru[i].id)
			instru[i].func(cmd, champ);
	}
	return true;
}

static bool wait_cycle(champion_t *champ)
{
	token_t *cmd = champ->token_list;

	for (uint64_t pc = 0; pc < champ->pc->pc && cmd; cmd = cmd->next)
		pc += cmd->nb_bytes;
	if (!cmd)
		return true;
	if (++champ->cycle_cmd >= op_tab[cmd->command - 1].nbr_cycles) {
		champ->cycle_cmd = 0;
		champ->pc->pc += cmd->nb_bytes;
		exec_instruction(cmd, champ);
	}
	return true;
}

bool exec_champ(champion_t *champ_list, vm_core_t *vm_core)
{
	for (champion_t *champ = champ_list; champ; champ = champ->next) {
		if (!wait_cycle(champ))
			return false;
	}
	return true;
}
