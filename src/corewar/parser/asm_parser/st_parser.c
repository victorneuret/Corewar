/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** st parser
*/

#include "corewar/parser/asm_parser.h"

bool st_parser(token_t *token, uint8_t *asm_token, int i)
{
	token_t *tmp = token;

	my_printf("%s\n", "st");
	init_token(tmp);
	tmp->command = asm_token[i];
	tmp->args_type = asm_token[i + 1];
	tmp->nb_bytes = 2;
	if (!asm_arg_parser(tmp, asm_token, i))
		return false;
	return true;
}
