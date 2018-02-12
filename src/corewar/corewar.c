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

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/corewar/README.txt");
	lexer("../Corewar_files/binaires-champ-corewar/"
		"corewar/assets/champions/abel.cor");
	return 0;
}
