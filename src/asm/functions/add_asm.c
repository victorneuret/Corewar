/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** add_asm
*/

#include "asm/functions/functions_array.h"
#include "asm/utils/clean_str.h"

static void check_label(char **array, uint8_t j, uint32_t *new_len,
label_t *label_s)
{
	if (is_label(array[j]))
		insert_label_call(false, array[j], new_len, label_s);
}

bool add_asm(int fd, char *args, uint32_t *new_len, label_t *label_s)
{
	uint8_t i = 4;
	int32_t value = 0;
	size_t size = 0;
	char **array = str_split(args, ',');

	if (!array)
		return false;
	new_len[1] = new_len[0];
	write(fd, &i, sizeof(uint8_t));
	write_function_value(fd, i, array);
	new_len[0] += 2;
	for (uint8_t j = 0; j < op_tab[i - 1].nbr_args; j++) {
		array[j] = clean_str(array[j]);
		check_label(array, j, new_len, label_s);
		value = get_arg_value(array[j], get_arg_size(array[j]));
		size = get_arg_bytes(get_arg_size(array[j]), &value,
		new_len, i);
		write(fd, &value, size);
	}
	free_str_array(array);
	return true;
}
