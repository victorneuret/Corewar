/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** fork_asm
*/

#include "asm/functions/functions_array.h"
#include "asm/utils/clean_str.h"

bool fork_asm(int fd, char *args, uint32_t *new_len, label_t *label_s)
{
	uint8_t i = 12;
	int16_t indirect = 0;
	char *str = substring(args, 1, my_strlen(args));

	if (!str)
		return false;
	str = clean_str(str);
	new_len[1] = new_len[0];
	if (is_label(args)) {
		//new_len[0] += 1;
		insert_label_call(true, args,
		(uint32_t[2]){new_len[0] + 1, new_len[1]}, label_s);
	}
	write(fd, &i, sizeof(uint8_t));
	indirect = (uint16_t) getnbr(str);
	indirect = reverse16_bits(indirect);
	new_len[0] += 3;
	write(fd, &indirect, sizeof(uint16_t));
	free(str);
	return true;
}
