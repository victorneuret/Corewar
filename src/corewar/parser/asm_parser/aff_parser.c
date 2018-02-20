/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** aff parser
*/

#include "corewar/parser/asm_parser.h"

bool aff_parser(token_t *token, char *asm_token, int *i)
{
	token_t *tmp = token;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	my_printf("%s\n", "aff");
	tmp->args_type = asm_token[*i + 1];
	tmp->nb_bytes = 2;
	if (!asm_arg_parser(tmp, asm_token, i))
		return false;
	*i -= 1;
	return true;
}
