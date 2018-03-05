/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** and & or & xor parser
*/

#include "corewar/parser/asm_parser.h"

bool and_parser(token_t *token, char *asm_token, int *i)
{
	token_t *tmp = token;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	switch (tmp->command) {
	case 6: my_printf("and\n"); break;
	case 7: my_printf("or\n"); break;
	case 8: my_printf("xor\n"); break;
	}
	tmp->args_type = asm_token[*i + 1];
	tmp->nb_bytes = 2;
	if (!asm_arg_parser(tmp, asm_token, i))
		return false;
	*i -= 1;
	return true;
}
