/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM Main file
*/

#include "include/asm/asm.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		puterr("Usage: ./asm champion.cor\n");
		return (84);
	} else if (str_eq(av[1], "-h") == 1)
		asm_help();
	write_file(av[1]);
	return 0;
}