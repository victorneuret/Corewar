/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool lfork_asm(int fd, __attribute__((unused)) char const *args)
{
	uint8_t i = 15;

	write(fd, &i, sizeof(uint8_t));
	return true;
}