/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"

#include "corewar/lexer/lexer.h"

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
	champion_t *champ_list = NULL;

	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/corewar/README.txt");
		else {
			champ_list = init_champion_list(av[i], champ_list);
			if (!champ_list)
				return 84;
		}
	return 0;
}
