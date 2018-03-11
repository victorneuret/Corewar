/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool sub_asm(int fd, char const *args, uint32_t *new_len,
__attribute__((unused)) label_t *label_s)
{
	uint8_t i = 5;
	int32_t value = 0;
	size_t size = 0;
	char **array = str_split(args, ',');

	if (!array)
		return false;
	write(fd, &i, sizeof(uint8_t));
	write_function_value(fd, i, array);
	*new_len += 2;
	for (uint8_t j = 0; j < op_tab[i - 1].nbr_args; j++) {
		value = get_arg_value(array[j], get_arg_size(array[j]));
		size = get_arg_bytes(get_arg_size(array[j]), &value,
		new_len, i);
		write(fd, &value, size);
	}
	free_str_array(array);
	return true;
}
