/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** init_corewar
*/

#include "corewar/corewar.h"

vm_core_t *init_vm_core(void)
{
	vm_core_t* vm_core = malloc(sizeof(vm_core_t));

	if (!vm_core)
		return NULL;
	vm_core->alive = false;
	vm_core->cycle_to_die = CYCLE_TO_DIE;
	vm_core->nb_live = 0;
	return vm_core;
}

static header_t read_header(char const *path)
{
	header_t header = {0};
	int fd = open(path, O_RDONLY);

	if (fd == -1)
		return header;
	if (read(fd, &header, sizeof(header)) <= 0)
		return header;
	close(fd);
	return header;
}

champion_t *init_champ_list(prog_t *programs, champion_t *champ_list)
{
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *tmp = champ_list;

	if (!new)
		return NULL;
	new->nb_champion = programs->prog_nb;
	new->token_list = NULL;
	new->asm_token_len = 0;
	new->header = read_header(programs->prog_path);
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
