/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** init_memory
*/

#include "corewar/corewar.h"

static bool check_mem_free(champion_t *champ, vm_core_t *vm_core, size_t pos)
{
	for (size_t i = 0; i < (size_t) champ->asm_token_len; i++) {
		if (vm_core->memory[pos + 1] != 0) {
			puterr("Overlap detected.\n");
			return false;
		}
	}
	return true;
}

static bool set_token_to_mem(size_t pos, champion_t *champ, vm_core_t *vm_core,
	int64_t addr)
{
	if (addr >= 0)
		pos = addr;
	if (!check_mem_free(champ, vm_core, pos))
		return false;
	for (size_t i = 0; i < (size_t) champ->asm_token_len; i++)
		if (vm_core->memory[pos + i] != 0)
			return false;
		else
			vm_core->memory[pos + i] = champ->asm_token[i];
	champ->pc->pc = pos;
	return true;
}

bool init_memory(champion_t *champ_list, vm_core_t *vm_core, args_t *arg)
{
	uint8_t pos = 0;

	for (champion_t *champ = champ_list; champ; champ = champ->next) {
		if (!set_token_to_mem(MEM_SIZE *
			(pos / (float) arg->champ_count), champ, vm_core,
			arg->programs[pos].load_addr))
			return false;
		pos++;
	}
	return true;
}
