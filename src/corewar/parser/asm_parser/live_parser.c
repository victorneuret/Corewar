/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** live parser
*/

#include "corewar/parser/asm_parser.h"

bool live_parser(token_t *token, uint8_t *asm_token, int i)
{
	token_t *tmp = token;
	int pc = i;

	my_printf("%s\n", "live");
	init_token(tmp);
	tmp->command = asm_token[i];
	tmp->args_type = 0;
	tmp->nb_bytes = 1;
	pc += 1;
	if (!asm_arg_direct(tmp, asm_token, 0, &pc))
		return false;
	return true;
}
