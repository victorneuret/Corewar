/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** parser_utils_2
*/

#include "corewar/parser/parser_utils.h"

void init_token(token_t *token)
{
	token->command = 0;
	token->args_type = 0;
	token->arg_one = 0;
	token->arg_two = 0;
	token->arg_three = 0;
	token->nb_bytes = 0;
	token->next = 0;
	token->prev = 0;
}

bool is_index_needed(token_t *token)
{
	return (token->command == 0x09 || token->command == 0x0a
		|| token->command == 0x0b || token->command == 0x0c
		|| token->command == 0x0e || token->command == 0x0f);
}
