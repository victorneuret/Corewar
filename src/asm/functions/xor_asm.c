/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool xor_asm(int fd, __attribute__((unused)) char const *args)
{
	uint8_t i = 8;

	write(fd, &i, sizeof(uint8_t));
	return true;
}
