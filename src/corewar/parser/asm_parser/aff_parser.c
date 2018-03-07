/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** aff parser
*/

#include "corewar/parser/asm_parser.h"

bool aff_parser(token_t *token, char *asm_token, int *i)
{
	token_t *tmp = token;

	my_printf("%s\n", "aff");
	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	tmp->args_type = asm_token[*i + 1];
	tmp->nb_bytes = 2;
	*i += 2;
	if (!asm_arg_register(tmp, asm_token, 0, i))
		return false;
	*i -= 1;
	return true;
}
