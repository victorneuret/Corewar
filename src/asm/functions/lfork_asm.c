/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool lfork_asm(int fd, char const *args, uint32_t *new_len)
{
	uint8_t i = 15;
	uint16_t value = 0;
	char *str = substring(args, 1, my_strlen(args));

	if (!str)
		return false;
	write(fd, &i, sizeof(uint8_t));
	value = (uint16_t) getnbr(str);
	value = reverse16_bits(value);
	*new_len += 3;
	write(fd, &value, sizeof(uint16_t));
	free(str);
	return true;
}
