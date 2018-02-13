/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include <stdio.h>

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"

#include "corewar/args.h"
#include "corewar/lexer/lexer.h"

static void free_champion_list(champion_t *champion_list)
{
	champion_t *tmp = champion_list;
	token_t *temp;

	while (champion_list) {
		tmp = champion_list->next;
		free(champion_list->exec_magic);
		free(champion_list->champion_name);
		free(champion_list->size);
		free(champion_list->comment);
		temp = champion_list->token_list;
		while (champion_list->token_list) {
			temp = champion_list->token_list->next;
			free(champion_list->token_list->token);
			free(champion_list->token_list);
			champion_list->token_list = temp;
		}
		free(champion_list);
		champion_list = tmp;
	}
}

static champion_t *init_champion_list(prog_t *programs, champion_t *champion_list)
{
	static int nb_champion = 1;
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *tmp = champion_list;

	if (!new)
		return NULL;
	new->nb_champion = programs->prog_nb;
	new = lexer(programs->prog_path, new);
	if (!new)
		return NULL;
	new->token_list = NULL;
	new->next = NULL;
	nb_champion++;
	if (!champion_list) {
		return new;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = new;
	}
	return tmp;
}

int main(int ac, char **av)
{
	args_t *args;
	champion_t *champ_list = NULL;

	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/corewar/README.txt");
	args = parse_arguments(av);
	if (!args)
		return 84;
	for (int i = 0; args->programs[i].prog_path; i++)
		champ_list = init_champion_list(&args->programs[i], champ_list);
	if (!champ_list)
		return 84;
	for (champion_t *tmp = champ_list; tmp; tmp = tmp->next)
		printf("%d %s\n", tmp->nb_champion, tmp->champion_name);
	free_args(args);
	free_champion_list(champ_list);
	return 0;
}
