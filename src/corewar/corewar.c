/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include <stdio.h>

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"

#include "corewar/args.h"
#include "corewar/lexer/lexer.h"

__attribute__((unused))
static champion_t *init_champion_list(char *champion_path,
	champion_t *champion_list)
{
	static int nb_champion = 1;
	champion_t *new = malloc(sizeof(champion_t));
	champion_t *tmp = champion_list;

	if (!new)
		return NULL;
	new->nb_champion = nb_champion;
	new = lexer(champion_path, new);
	if (!new)
		return NULL;
	new->token_list = NULL;
	new->next = NULL;
	nb_champion++;
	if (!champion_list) {
		return new;
	} else {
		for (; tmp->next; tmp = tmp->next);
		tmp->next = new;
	}
	return tmp;
}

int main(int ac, char **av)
{
	__attribute__((unused)) champion_t *champion_list = NULL;
	args_t *args;

	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/corewar/README.txt");
	args = parse_arguments(av);
	if (!args)
		return 84;
	free_args(args);
	return 0;
}
