/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** add & sub parser
*/

#include "corewar/parser/asm_parser.h"

bool add_parser(token_t *token, uint8_t *asm_token, int i)
{
	token_t *tmp = token;

	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[i];
	if (tmp->command == 4)
		my_printf("%s\n", "add");
	else if (tmp->command == 5)
		my_printf("%s\n", "sub");
	tmp->args_type = asm_token[i + 1];
	tmp->nb_bytes = 2;
	if (!asm_arg_parser(tmp, asm_token, i))
		return false;
	return true;
}
