/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Parser
*/

#include "corewar/parser/parser.h"

static const asm_parser_t pars_asm[] = {
	{1, &live_parser},
	{2, &ld_parser},
	{3, &st_parser},
	{4, &add_parser},
	{5, &add_parser},
	{6, &and_parser},
	{7, &and_parser},
	{8, &and_parser},
	{9, &zjmp_parser},
	{10, &ldi_parser},
	{11, &sti_parser},
	{12, &fork_parser},
	{13, &lld_parser},
	{14, &lldi_parser},
	{15, &fork_parser},
	{16, &aff_parser},
	{0, NULL}
};

static token_t *init_list_pars(token_t *token)
{
	token_t *tmp = token;

	if (!token) {
		token = malloc(sizeof(token_t));
		if (!token)
			return NULL;
		init_token(token);
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = malloc(sizeof(token_t));
		if (!tmp->next)
			return NULL;
		init_token(tmp->next);
		tmp->next->prev = tmp;
	}
	return token;
}

static bool call_function_parser(champion_t *champ, int *i, int j)
{
	champ->token_list = init_list_pars(champ->token_list);
	if (!champ->token_list)
		return false;
	return (pars_asm[j].func(champ->token_list, champ->asm_token, i));
}

static bool parser_op_tab(champion_t *champ, int *i)
{
	for (int j = 0; op_tab[j].mnemonique; j++)
		if (champ->asm_token[*i] == op_tab[j].code) {
			return call_function_parser(champ, i, j);
		}
	return true;
}

bool parser(champion_t *champ)
{
	for (int i = 0; i < champ->asm_token_len; i++)
		if (!parser_op_tab(champ, &i))
			return false;
	return true;
}
