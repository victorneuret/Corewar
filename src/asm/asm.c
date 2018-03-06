/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
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
			return print_file_bytes("src/asm/README.txt") ? 0 : 84;
	asm_struct.executable = av[0];
	asm_struct.filename = av[1];
	if (!compile(av[1], &asm_struct)) {
		puterr("Compilation failed.\n");
		return 84;
	}
	free(asm_struct.name);
	free(asm_struct.comment);
	free_str_array(asm_struct.array);
	return 0;
}
