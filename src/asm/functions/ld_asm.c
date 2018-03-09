/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool ld_asm(int fd, char const *args)
{
	uint8_t registery = 2;
	uint16_t direct = 0;
	uint32_t indirect = 0;

	write(fd, &registery, sizeof(uint8_t));
	return true;
}
