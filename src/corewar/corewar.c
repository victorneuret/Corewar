/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** CPE_corewar_2017 Main file
*/

#include <stdio.h>

#include "corewar/corewar.h"

static bool run_vm(champion_t *champ_list, vm_core_t *vm_core)
{
	for (vm_core->cycle = 0; vm_core->cycle < CYCLE_TO_DIE
		- vm_core->cycle_to_die_sub; vm_core->cycle++) {
		if (!exec_champ(champ_list, vm_core))
			return false;
		if (vm_core->alive && vm_core->nb_live >= NBR_LIVE)
			vm_core->cycle_to_die_sub += CYCLE_DELTA;
	}
	return true;
}

static bool is_valid_exec_magic(champion_t *champ_list)
{
	int exec_magic = reverse_bits(COREWAR_EXEC_MAGIC);
	champion_t *current = champ_list;

	for (; current; current = current->next)
		if (current->header.magic != exec_magic) {
			puterr(current->header.prog_name);
			puterr(": Invalid executable.\n");
			return false;
		}
	return true;
}

static bool start_vm(args_t *args)
{
	champion_t *champ_list = NULL;
	vm_core_t *vm_core = init_vm_core();

	champ_list = init_champions(args, champ_list);
	if (!champ_list || !vm_core)
		return false;
	if (!is_valid_exec_magic(champ_list))
		return false;
	//for (champion_t *tmp = champ_list; tmp; tmp = tmp->next)
	// print_token_list(champ_list->token_list);
	if (!run_vm(champ_list, vm_core))
		return false;
	free_champion_list(champ_list);
	free(vm_core);
	return true;
}

static bool corewar(int ac, char **av)
{
	args_t *args;

	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_bytes("src/corewar/README.txt");
	args = parse_arguments(av);
	if (!args)
		return false;
	start_vm(args);
	free_args(args);
	return true;
}

int main(int ac, char **av)
{
	if (!corewar(ac, av))
		return 84;
	return 0;
}
