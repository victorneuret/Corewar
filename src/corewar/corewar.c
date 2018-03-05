/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** CPE_corewar_2017 Main file
*/

#include <stdio.h>

#include "corewar/corewar.h"

static bool start_vm(args_t *args)
{
	champion_t *champ_list = NULL;

	champ_list = init_champions(args, champ_list);
	if (!champ_list)
		return false;
	print_token_list(champ_list->token_list);
	free_champion_list(champ_list);
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
