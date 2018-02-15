/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include <stdio.h>

#include "corewar/corewar.h"

static champion_t *init_champ_list(prog_t *programs, champion_t *champ_list)
{
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *tmp = champ_list;

	if (!new)
		return NULL;
	new->nb_champion = programs->prog_nb;
	new->token_list = NULL;
	new = lexer(programs->prog_path, new);
	if (!new)
		return NULL;
	new->next = NULL;
	if (!champ_list) {
		return new;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = new;
	}
	return tmp;
}

static champion_t *init_champions(args_t *args, champion_t *champ_list)
{
	for (int i = 0; args->programs[i].prog_path; i++)
		champ_list = init_champ_list(&args->programs[i], champ_list);
	if (!champ_list) {
		free_args(args);
		return NULL;
	}
	for (champion_t *tmp = champ_list; tmp; tmp = tmp->next)
		parser(tmp);
	return champ_list;
}

static bool corewar(int ac, char **av)
{
	args_t *args;
	champion_t *champ_list = NULL;

	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/corewar/README.txt");
	args = parse_arguments(av);
	if (!args)
		return false;
	champ_list = init_champions(args, champ_list);
	if (!champ_list)
		return false;
	free_args(args);
	free_champion_list(champ_list);
	return true;
}

int main(int ac, char **av)
{
	if (!corewar(ac, av))
		return 84;
	return 0;
}
