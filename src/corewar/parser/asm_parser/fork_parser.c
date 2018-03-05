/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fork & lfork parser
*/

#include "corewar/parser/asm_parser.h"

bool fork_parser(token_t *token, char *asm_token, int *i)
{
	token_t *tmp = token;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	switch (tmp->command) {
	case 12: my_printf("fork\n"); break;
	case 15: my_printf("lfork\n"); break;
	}
	tmp->args_type = 0;
	tmp->nb_bytes = 1;
	*i += 1;
	if (!asm_arg_indirect(tmp, asm_token, 0, i))
		return false;
	*i -= 1;
	return true;
}
