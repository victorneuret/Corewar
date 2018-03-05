/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Parser debugger
*/

#include "corewar/parser/parser.h"

void print_token(token_t *token)
{
	if (!token) {
		my_printf("Null token..\n\n");
		return;
	}
	my_printf("\nToken %p:\n", token);
	my_printf("\tcommand:\t%#x\n", token->command);
	my_printf("\targs_type:\t%#x\n", token->args_type);
	my_printf("\targ_one:\t%#x\n", token->arg_one);
	my_printf("\targ_two:\t%#x\n", token->arg_two);
	my_printf("\targ_three:\t%#x\n", token->arg_three);
	my_printf("\tnb_bytes:\t%#x\n", token->nb_bytes);
	my_printf("\tprev:\t\t%p\n", token->prev);
	my_printf("\tnext:\t\t%p\n", token->next);
}

void print_token_list(token_t *head)
{
	token_t *current = head;

	while (current) {
		print_token(current);
		current = current->next;
	}
}
