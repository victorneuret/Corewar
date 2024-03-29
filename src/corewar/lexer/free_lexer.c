/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** free_lexer
*/

#include "corewar/lexer/free_lexer.h"

void free_champion_list(champion_t *champion_list)
{
	champion_t *tmp = champion_list;
	token_t *temp = NULL;

	while (champion_list) {
		tmp = champion_list->next;
		free(champion_list->asm_token);
		for (pc_t *pc = champion_list->pc; champion_list->pc;
			champion_list->pc = pc) {
			pc = champion_list->pc->next;
			free(champion_list->pc);
		}
		while (champion_list->token_list) {
			temp = champion_list->token_list->next;
			free(champion_list->token_list);
			champion_list->token_list = temp;
		}
		free(champion_list);
		champion_list = tmp;
	}
}
