/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM Main file
*/

#include "asm/asm.h"

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		puterr("Usage: ./asm champion.cor\n");
		return 84;
	}
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/asm/README.txt");
	write_file(av[1]);
	return 0;
}