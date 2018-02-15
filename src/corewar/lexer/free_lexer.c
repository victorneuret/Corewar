/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** free_lexer
*/

#include "corewar/lexer/free_lexer.h"

void free_champion_list(champion_t *champion_list)
{
	champion_t *tmp = champion_list;

	while (champion_list) {
		tmp = champion_list->next;
		free(champion_list->exec_magic);
		free(champion_list->champion_name);
		free(champion_list->size);
		free(champion_list->comment);
		free(champion_list->asm_token);
		free(champion_list);
		champion_list = tmp;
	}
}
