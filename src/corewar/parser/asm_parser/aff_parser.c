/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** aff parser
*/

#include "corewar/parser/asm_parser.h"

bool aff_parser(__attribute__((unused)) token_t *token,
	__attribute__((unused)) char *asm_token,
	__attribute__((unused)) int *i)
{
	token_t *tmp = token;

	my_printf("%s\n", "aff");
	for (; tmp->next; tmp = tmp->next);
	tmp->command = asm_token[*i];
	tmp->args_type = asm_token[*i + 1];
	tmp->nb_bytes = 1;
	*i += 2;
	if (!asm_arg_register(tmp, asm_token, 0, i))
		return false;
	return true;
}
