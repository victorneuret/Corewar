/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** live_asm
*/

#include "asm/functions/functions_array.h"
#include "asm/utils/clean_str.h"

bool live_asm(int fd, char *args, uint32_t *new_len, label_t *label_s)
{
	uint8_t registery = 1;
	int32_t indirect = 0;
	char *str = substring(args, 1, my_strlen(args));

	if (!str)
		return false;
	str = clean_str(str);
	new_len[1] = new_len[0];
	write(fd, &registery, sizeof(uint8_t));
	if (is_label(args)) {
		insert_label_call(true, args, (uint32_t[2]){new_len[0] + 1,
		new_len[1]}, label_s);
	}
	indirect = (uint32_t) getnbr(str);
	indirect = reverse_bits(indirect);
	new_len[0] += 5;
	write(fd, &indirect, sizeof(uint32_t));
	free(str);
	return true;
}
