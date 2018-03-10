/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** parameters_types.c
*/

#include "asm/lexer/parameters_types.h"

static uint8_t register_type(char *arg, int j)
{
	char *nbr = NULL;
	int nb = 0;

	nbr = substring(arg, j + 1, my_strlen(arg));
	if (!is_number(nbr)) {
		free(nbr);
		return 0;
	}
	nb = getnbr(nbr);
	free(nbr);
	if (nb >= 1 && nb <= REG_NUMBER)
		return T_REG;
	return 0;
}

static uint8_t direct_type(char *arg, int j)
{
	char *nbr = NULL;
	int64_t nb = 0;

	nbr = substring(arg, j + 1, my_strlen(arg));
	if (nbr[0] == '-') {
		free(nbr);
		return 0;
	}
	if (!is_number(nbr)) {
		free(nbr);
		return 0;
	}
	nb = getnbr(nbr);
	free(nbr);
	if (nb <= TWO_BYTES_MAX_SIZE)
		return T_DIR;
	return 0;
}

uint8_t check_arguments_type(char *arg, int j)
{
	if (arg[j] == 'r')
		return register_type(arg, j);
	else if (arg[j] == DIRECT_CHAR)
		return direct_type(arg, j);
	return 0;
}
