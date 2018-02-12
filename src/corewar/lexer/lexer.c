/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** lexer
*/

#include "corewar/lexer/lexer.h"

token_t *lexer(char *champion)
{
	token_t *token = champion_name(champion);

	if (!token)
		return NULL;
	return token;
}
