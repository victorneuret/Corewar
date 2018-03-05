/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** live parser
*/

#include "corewar/parser/asm_parser.h"

bool live_parser(token_t *token, char *asm_token, int *i)
{
	token_t *tmp = token;

	my_printf("%s\n", "live");
	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	tmp->args_type = 0;
	tmp->nb_bytes = 1;
	*i += 1;
	if (!asm_arg_direct(tmp, asm_token, 0, i))
		return false;
	*i -= 1;
	return true;
}
