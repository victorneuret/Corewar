/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** dump
*/

#include "corewar/corewar.h"

bool dump(vm_core_t *vm_core)
{
	for (size_t i = 0; i < MEM_SIZE; i++) {
		if (i == 0)
			my_printf("\n\nDump :\n0\t: ");
		if (vm_core->memory[i] <= 15)
			my_printf("0");
		my_printf("%x ", vm_core->memory[i]);
		if ((i + 1) % 8 == 0 && i != 0)
			my_printf(" ");
		if ((i + 1) % 4 == 0 && i != 0)
			my_printf(" ");
		if ((i + 1) % 32 == 0 && i != 0 && i + 1 < MEM_SIZE)
			my_printf("\n%x\t: ", i + 1);
		else if ((i + 1) % 32 == 0 && i != 0)
			my_printf("\n");
	}
	return true;
}
