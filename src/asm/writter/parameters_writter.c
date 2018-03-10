/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Parameters writter
*/

#include "asm/writter/parameters_writter.h"

uint32_t get_arg_value(char const *arg, uint8_t code)
{
	uint32_t value = 0;
	uint8_t i = 0;
	char *str = NULL;

	for (;arg[i] != '\0' && (arg[i] == ' ' || arg[i] == '\t'); i++);
	if (code == T_REG || code == T_DIR)
		i += 1;
	str = substring(arg, i, my_strlen(arg));
	if (!str)
		return 0;
	value = getnbr(str);
	free(str);
	return value;
}

uint8_t get_arg_size(char const *arg)
{
	uint8_t i = 0;

	for (;arg[i] != '\0' && (arg[i] == ' ' || arg[i] == '\t'); i++);
	switch (arg[i]) {
	case 'r': return T_REG;
	case DIRECT_CHAR: return T_DIR;
	default: return T_IND;
	}
}

size_t get_arg_bytes(uint8_t code, uint32_t *value, uint32_t *new_len)
{
	if (code == T_REG) {
		*new_len += 1;
		return sizeof(uint8_t);
	}
	else if (code == T_IND) {
		*value = reverse16_bits(*value);
		*new_len += 2;
		return sizeof(uint16_t);
	} else {
		*value = reverse_bits(*value);
		*new_len += 4;
		return sizeof(uint32_t);
	}
}

uint8_t bitwise(uint8_t b, uint8_t a)
{
	return ((b + a) << 2);
}

void write_function_value(int fd, uint8_t i, char **array)
{
	uint8_t value = 0;
	uint8_t nb = 2;
	uint8_t j = 0;

	for (; j < op_tab[i - 1].nbr_args; j++) {
		nb = get_arg_size(array[j]);
		if (nb == 4)
			nb -= 1;
		value = bitwise(value, nb);
	}
	for (; j < 3; j++)
		value = bitwise(value, 0);
	write(fd, &value, sizeof(uint8_t));
}
