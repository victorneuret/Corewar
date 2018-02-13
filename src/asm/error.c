/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Error.c
*/

#include "asm/asm.h"

int check_format(asm_t *asm_struct)
{
	int i = 0;

	while (asm_struct->array[i][0] != '\0');
	return (0);
}

void check_file(asm_t *asm_struct)
{
	check_format(asm_struct);
}
