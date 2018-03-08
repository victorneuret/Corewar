/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_champion
*/

#include "corewar/vm/exec_champion.h"

static const exec_instruction_t instru[] = {
	{1, &exec_live},
	{2, &exec_ld},
	{3, &exec_st},
	{4, &exec_add},
	{5, &exec_sub},
	{6, &exec_and},
	{7, &exec_or},
	{8, &exec_xor},
	{9, &nope},
	{10, &nope},
	{11, &exec_sti},
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
	my_printf("nope\n");
	return;
}

static bool exec_instruction(token_t *cmd, champion_t *champ)
{
	for (int i = 0; instru[i].id; i++) {
		if (cmd->command == instru[i].id) {
			instru[i].func(cmd, champ);
			break;
		}
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
	if (vm_core->cycle >= vm_core->cycle_to_die)
		vm_core->alive = false;
	for (champion_t *champ = champ_list; champ; champ = champ->next) {
		if (!champ->alive || !wait_cycle(champ))
			return false;
		if (champ->live) {
			vm_core->last_alive = champ->nb_champion;
			vm_core->champ_name = champ->header.prog_name;
			vm_core->alive = true;
			champ->live = false;
			champ->alive = true;
			vm_core->nb_live++;
		}
	}
	return true;
}
