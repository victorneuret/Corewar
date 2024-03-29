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
	for (vm_core->cycle = 0; vm_core->alive; vm_core->cycle++) {
		if (vm_core->cycle_to_die <= 1)
			break;
		switch (exec_champ(champ_list, vm_core)) {
		case -1: return false;
		case 1: continue;
		}
		if (vm_core->nb_live >= NBR_LIVE) {
			vm_core->cycle_to_die -= CYCLE_DELTA;
			vm_core->nb_live = 0;
		}
		vm_core->cycle_before_die++;
		if ((int64_t) vm_core->cycle == vm_core->dump) {
			dump(vm_core);
			break;
		}
	}
	if (vm_core->champ_name)
		my_printf("The player %d(%s) has won.\n",
			vm_core->last_alive, vm_core->champ_name);
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
	vm_core_t *vm_core = init_vm_core(args);

	champ_list = init_champions(args, champ_list);
	if (!champ_list || !vm_core)
		return false;
	if (!is_valid_exec_magic(champ_list))
		return false;
	if (!init_memory(champ_list, vm_core, args)
		|| !run_vm(champ_list, vm_core))
		return false;
	free_champion_list(champ_list);
	free(vm_core);
	return true;
}

static bool corewar(int ac, char **av)
{
	args_t *args;
	bool vm_exit = false;

	if (ac == 1)
		return false;
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_bytes("src/corewar/README.txt");
	args = parse_arguments(av);
	if (args->champ_count < 2)
		return true;
	if (!args)
		return false;
	if (champions_exist(args) && attribute_ids(args)) {
		vm_exit = start_vm(args);
	} else {
		free_args(args);
		return false;
	}
	free_args(args);
	return vm_exit;
}

int main(int ac, char **av)
{
	if (!corewar(ac, av))
		return 84;
	return 0;
}
