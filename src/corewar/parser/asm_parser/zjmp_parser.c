/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** zjmp parser
*/

#include "corewar/parser/asm_parser.h"

bool zjmp_parser(token_t *token, char *asm_token, int *i)
{
	token_t *tmp = token;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	my_printf("zjmp\n");
	tmp->args_type = 0;
	tmp->nb_bytes = 1;
	*i += 1;
	if (!asm_arg_indirect(tmp, asm_token, 0, i))
		return false;
	*i -= 1;
	return true;
}
