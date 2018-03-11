/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** parameters_types.c
*/

#include "asm/lexer/parameters_types.h"

static uint8_t register_type(char *arg, int j, asm_t *asm_s)
{
	char *nbr = NULL;
	int nb = 0;

	nbr = substring(arg, j + 1, my_strlen(arg));
	if (!is_number(nbr)) {
		syntax_error(asm_s, error_message[5]);
		free(nbr);
		return 0;
	}
	nb = getnbr(nbr);
	free(nbr);
	if (nb >= 1 && nb <= REG_NUMBER)
		return T_REG;
	syntax_error(asm_s, error_message[8]);
	return 0;
}

static uint8_t direct_type(char *arg, int j, asm_t *asm_s)
{
	char *nbr = NULL;
	int64_t nb = 0;

	nbr = substring(arg, j + 1, my_strlen(arg));
	if (nbr[0] == '-' || !is_number(nbr)) {
		syntax_error(asm_s, error_message[5]);
		free(nbr);
		return 0;
	}
	nb = getnbr(nbr);
	free(nbr);
	if (nb <= TWO_BYTES_MAX_SIZE)
		return T_DIR;
	syntax_error(asm_s, error_message[5]);
	return 0;
}

static uint8_t label_type(char *arg, int j,
__attribute__((unused)) asm_t *asm_s)
{
	char *nbr = NULL;
	__attribute__((unused)) int64_t nb = 0;

	nbr = substring(arg, j + 2, my_strlen(arg));
	if (nbr[0] == '-') {
		free(nbr);
		return 0;
	}
	free(nbr);
	return 0;
}

static uint8_t indirect_type(char *arg, int j, asm_t *asm_s)
{
	char *nbr = NULL;
	int64_t nb = 0;

	nbr = substring(arg, j, my_strlen(arg));
	if (nbr[0] == '-' || !is_number(nbr)) {
		syntax_error(asm_s, error_message[5]);
		free(nbr);
		return 0;
	}
	nb = getnbr(nbr);
	free(nbr);
	if (nb <= FOUR_BYTES_MAX_SIZE)
		return T_IND;
	syntax_error(asm_s, error_message[5]);
	return 0;
}

uint8_t check_arguments_types(char *arg, int j, asm_t *asm_s)
{
	if (arg[j] == 'r')
		return register_type(arg, j, asm_s);
	else if (arg[j] == DIRECT_CHAR) {
		if (arg[j + 1] == LABEL_CHAR)
			return label_type(arg, j, asm_s);
		else
			return direct_type(arg, j, asm_s);
	} else
		return indirect_type(arg, j, asm_s);
	return 0;
}
