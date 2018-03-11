/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool zjmp_asm(int fd, char *args, uint32_t *new_len, label_t *label_s)
{
	uint8_t i = 9;
	int16_t indirect = 0;
	char *str = substring(args, 1, my_strlen(args));

	if (!str)
		return false;
	write(fd, &i, sizeof(uint8_t));
	if (is_label(args))
		insert_label_call(true, args, *new_len + 1, label_s);
	indirect = (uint16_t) getnbr(str);
	indirect = reverse16_bits(indirect);
	*new_len += 3;
	write(fd, &indirect, sizeof(uint16_t));
	free(str);
	return true;
}
