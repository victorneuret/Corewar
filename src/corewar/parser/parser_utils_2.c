/*
** EPITECH PROJECT, 2018
** Corewar
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
