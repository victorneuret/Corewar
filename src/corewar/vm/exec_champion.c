/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_champion
*/

#include "corewar/vm/exec_champion.h"

static bool exec_instruction(champion_t *champ)
{
	token_t *cmd = champ->token_list;

	for(uint64_t pc = 0; pc < champ->pc->pc && cmd; cmd = cmd->next) {
		pc += cmd->nb_bytes;
	}
	print_token(cmd);
	if (!cmd) {
		champ->carry = false;
		return true;
	}
	my_printf("nbr_cycles: %d ", op_tab[cmd->command].nbr_cycles);
	my_printf("for: %d	", cmd->command);
	my_printf("now: %d\n", champ->cycle_cmd);
	// my_printf("nbr_cycles: %d for: %d      now: %d\n",
	// op_tab[cmd->command].nbr_cycles, cmd->command, champ->cycle_cmd);
	if (++champ->cycle_cmd >= op_tab[cmd->command - 1].nbr_cycles) {
		champ->cycle_cmd = 0;
		champ->pc->pc += cmd->nb_bytes;
	}
	return true;
}

bool exec_champ(champion_t *champ_list, vm_core_t *vm_core)
{
	for (champion_t *champ = champ_list; champ; champ = champ->next) {
		if (!exec_instruction(champ))
			return false;
		if (champ->carry == false)
			vm_core->alive = false;
	}
	return true;
}
