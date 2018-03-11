/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_fork
*/

#include "corewar/vm/exec_champion.h"

static bool add_fork_value(champion_t *new, champion_t *champ, uint16_t arg)
{
	new->nb_champion = champ->nb_champion;
	new->asm_token_len = champ->asm_token_len;
	new->asm_token = (uint8_t *) my_strdup((char *) champ->asm_token);
	new->header = champ->header;
	new->token_list = malloc(sizeof(token_t));
	if (!new->token_list || !init_pc_reg(new))
		return NULL;
	init_token(new->token_list);
	new->cycle_cmd = 0;
	new->carry = champ->carry;
	new->pc->pc = champ->pc->pc + arg;
	for (size_t i = 0; i < REG_NUMBER; i++)
		new->reg[i] = champ->reg[i];
	return true;
}

champion_t *add_champ_fork(champion_t *champ, uint16_t arg_one)
{
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *tmp = champ;

	if (!new)
		return NULL;
	if (!add_fork_value(new, champ, arg_one))
		return false;
	new->next = NULL;
	for (; tmp->next; tmp = tmp->next);
	tmp->next = new;
	return champ;
}

void exec_fork(token_t *token, champion_t *champ,
	__attribute__((unused)) vm_core_t *vm)
{
	champ = add_champ_fork(champ, (uint16_t) token->arg_one % IDX_MOD);
	if (!champ)
		return;
}
