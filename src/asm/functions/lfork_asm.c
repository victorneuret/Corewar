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
	uint16_t value = 0;
	char *str = substring(args, 1, my_strlen(args));

	if (!str)
		return false;
	write(fd, &i, sizeof(uint8_t));
	value = (uint32_t) getnbr(str);
	value = reverse16_bits(value);
	write(fd, &value, sizeof(uint16_t));
	free(str);
	return true;
}
