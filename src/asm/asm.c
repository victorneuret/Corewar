/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** ASM Main file
*/

#include "asm/asm.h"

#include "asm/utils/label_list.h"

static void free_struct(asm_t *asm_struct)
{
	if (asm_struct->name)
		free(asm_struct->name);
	if (asm_struct->comment)
		free(asm_struct->comment);
	if (asm_struct->array)
		free_str_array(asm_struct->array);
	if (asm_struct->labels)
		free_str_array(asm_struct->labels);
}

int main(int ac, char **av)
{
	asm_t asm_struct = {0};

	if (ac != 2) {
		puterr(USAGE_MESSAGE);
		return 84;
	}
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], HELP_ARGUMENT))
			return print_file_bytes(README_PATH) ? 0 : 84;
	asm_struct.executable = av[0];
	asm_struct.filename = av[1];
	if (!compile(av[1], &asm_struct)) {
		if (asm_struct.array)
			free_str_array(asm_struct.array);
		return 84;
	}
	free_struct(&asm_struct);
	return 0;
}
