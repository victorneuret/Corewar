/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool live_asm(int fd, char const *args)
{
	uint8_t registery = 1;
	uint32_t indirect = 0;

	write(fd, &registery, sizeof(uint8_t));
	indirect = (uint32_t) getnbr(substring(args, 1, my_strlen(args)));
	indirect = reverse_bits(indirect);
	write(fd, &indirect, sizeof(uint32_t));
	return true;
}
