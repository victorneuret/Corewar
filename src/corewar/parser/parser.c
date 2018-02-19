/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Parser
*/

#include "corewar/parser/parser.h"

static asm_parser_t pars_asm[] = {
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

static token_t *init_parser_list(token_t *token)
{
	token_t *tmp = token;

	if (!token) {
		token = malloc(sizeof(token_t));
		if (!token)
			return NULL;
		token->next = NULL;
		token->prev = NULL;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = malloc(sizeof(token_t));
		if (!tmp->next)
			return NULL;
		tmp->next->prev = tmp;
		tmp->next->next = NULL;
	}
	return token;
}

bool parser_op_tab(champion_t *champ, int *i)
{

	for (int j = 0; op_tab[j].mnemonique; j++)
		if (champ->asm_token[*i] == op_tab[j].code)
			return (pars_asm[j].func(champ->token_list,
				champ->asm_token, i));
	return true;
}

bool parser(champion_t *champ)
{
	champ->token_list = init_parser_list(champ->token_list);
	if (!champ->token_list)
		return false;
	for (int i = 0; i < champ->asm_token_len; i++)
		if (!parser_op_tab(champ, &i))
			return false;
	return true;
}
