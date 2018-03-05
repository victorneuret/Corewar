/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** init_corewar
*/

#include "corewar/corewar.h"

champion_t *init_champ_list(prog_t *programs, champion_t *champ_list)
{
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *tmp = champ_list;

	if (!new)
		return NULL;
	new->nb_champion = programs->prog_nb;
	new->token_list = NULL;
	new->asm_token_len = 0;
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

champion_t *init_champions(args_t *args, champion_t *champ_list)
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
