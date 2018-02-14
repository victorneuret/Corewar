/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM Main file
*/

#include "asm/asm.h"

static bool compile(asm_t *asm_s)
{
	char **lines = asm_s->array;

	if (!lines)
		return false;
	for (size_t i = 0; lines[i]; i++) {
		my_printf("%s\n", lines[i]);
	}
	return true;
}

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
	if (file_handling(av[1], &asm_struct) == 84)
		return (84);
	my_printf("Hi there\n");
	if (!compile(&asm_struct)) {
		puterr("Compilation failed.\n");
		return 84;
	}
	return 0;
}
