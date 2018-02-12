/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include <stdio.h>
#include <stdlib.h>

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"
#include "corewar/lexer/lexer.h"

static int print_help(void)
{
	char *line = 0;
	size_t n = 0;
	FILE *file = fopen("README.txt", "r");

	if (!file)
		return 84;
	while (getline(&line, &n, file) > 0 && line) {
		putstr(line);
		free(line);
		line = 0;
	}
	free(line);
	fclose(file);
	return 0;
}

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_help();
	my_printf("Hello %s!\n", "world");
	lexer("../Corewar_files/binaires-champ-corewar/"
		"corewar/assets/champions/abel.cor");
	return 0;
}
