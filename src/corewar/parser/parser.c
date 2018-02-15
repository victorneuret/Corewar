/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
**
*/

#include "corewar/parser/parser.h"

static token_t *init_parser_list(token_t *token)
{
	token_t *tmp = token;

	if (!token) {
		token = malloc(sizeof(token_t));
		if (!token)
			return NULL;
		token->next = NULL;
		token->prev = NULL;
		token->command = 21;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = malloc(sizeof(token_t));
		if (!tmp->next)
			return NULL;
		tmp->next->prev = tmp;
		tmp->next->next = NULL;
		tmp->next->command = 42;
	}
	return token;
}

bool parser(champion_t *champ)
{
	champ->token_list = init_parser_list(champ->token_list);
	if (!champ->token_list)
		return false;
	return true;
}
