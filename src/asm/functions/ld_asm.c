/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool ld_asm(__attribute__((unused)) int fd)
{
	uint8_t i = 2;

	write(fd, &i, sizeof(int));
	return true;
}
