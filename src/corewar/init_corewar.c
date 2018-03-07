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
	vm_core->alive = true;
	vm_core->cycle_to_die = CYCLE_TO_DIE;
	vm_core->last_alive = 0;
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

static bool init_pc_reg(champion_t *new)
{
	new->pc = malloc(sizeof(pc_t));
	if (!new->pc)
		return false;
	new->pc->next = NULL;
	new->pc->pc = 0;
	for (uint8_t i = 0; i < REG_NUMBER; i++)
		new->reg[i] = 0;
	new->alive = true;
	new->live = false;
	return true;
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
	new->cycle_cmd = 0;
	new = lexer(programs->prog_path, new);
	if (!new || !init_pc_reg(new))
		return NULL;
	new->carry = false;
	new->next = NULL;
	if (!champ_list)
		return new;
	for (; tmp->next; tmp = tmp->next);
	tmp->next = new;
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
