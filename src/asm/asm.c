/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM Main file
*/

#include "asm/asm.h"

int main(int ac, char **av)
{
	asm_t asm_struct;

	if (ac != 2) {
		puterr("Usage: ./asm champion.cor\n");
		return 84;
	}
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_file_content("src/asm/README.txt");
	if (!compile(av[1], &asm_struct)) {
		puterr("Compilation failed.\n");
		return 84;
	}
	free_str_array(asm_struct.array);
	return 0;
}
