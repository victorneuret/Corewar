/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include <stdio.h>

#include "corewar/corewar.h"

static bool run_vm(__attribute__ ((unused)) champion_t *champ_list,
	vm_core_t *vm_core)
{
	for (uint64_t cycle = 0; true; cycle++) {
		if (vm_core->alive && vm_core->nb_live >= NBR_LIVE)
			vm_core->cycle_to_die -= CYCLE_DELTA;
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
	print_token_list(champ_list->token_list);
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
