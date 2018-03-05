/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** parser utils
*/

#include "corewar/parser/parser_utils.h"

int bytes_sum(char a, char b, char c, char d)
{
	int int_a = ABS_CHAR(a);
	int int_b = ABS_CHAR(b);
	int int_c = ABS_CHAR(c);
	int int_d = ABS_CHAR(d);

	return (int_a * 1048576 + int_b * 4096 + int_c * 256 + int_d);
}

bool asm_arg_direct(token_t *token, char *asm_token, int k, int *i)
{
	char *dir = substring(asm_token, *i, *i + DIR_SIZE);

	if (!dir)
		return false;
	switch (k + 1) {
	case 1: token->arg_one = bytes_sum(dir[0], dir[1], dir[2], dir[3]);
		break;
	case 2: token->arg_two = bytes_sum(dir[0], dir[1], dir[2], dir[3]);
		break;
	case 3: token->arg_three = bytes_sum(dir[0], dir[1], dir[2], dir[3]);
		break;
	}
	token->nb_bytes += is_index_needed(token) ? 2 : DIR_SIZE;
	*i += is_index_needed(token) ? 2 : DIR_SIZE;
	free(dir);
	return true;
}

bool asm_arg_indirect(token_t *token, char *asm_token, int k, int *i)
{
	char *dir = substring(asm_token, *i, *i + IND_SIZE);

	if (!dir)
		return false;
	switch (k + 1) {
	case 1: token->arg_one = bytes_sum(0, 0, dir[0], dir[1]);
		break;
	case 2: token->arg_two = bytes_sum(0, 0, dir[0], dir[1]);
		break;
	case 3: token->arg_three = bytes_sum(0, 0, dir[0], dir[1]);
		break;
	}
	token->nb_bytes += IND_SIZE;
	*i += IND_SIZE;
	free(dir);
	return true;
}

bool asm_arg_register(token_t *token, char *asm_token, int k, int *i)
{
	char *reg = substring(asm_token, *i, *i + 1);

	if (!reg)
		return false;
	switch (k + 1) {
	case 1: token->arg_one = reg[0]; break;
	case 2: token->arg_two = reg[0]; break;
	case 3: token->arg_three = reg[0]; break;
	}
	token->nb_bytes += 1;
	*i += 1;
	free(reg);
	return true;
}

bool asm_arg_parser(token_t *token, char *asm_token, int *i)
{
	int div = token->args_type;
	bool ret_val = true;
	int bit_shift = 6;

	*i += 2;
	for (int k = 0; k < MAX_ARGS_NUMBER; k++) {
		switch ((div >> bit_shift) & 3) {
		case 1: ret_val = asm_arg_register(token, asm_token, k, i);
			break;
		case 2: ret_val = asm_arg_direct(token, asm_token, k, i);
			break;
		case 3: ret_val = asm_arg_indirect(token, asm_token, k, i);
			break;
		case 0: break;
		default: return false;
		}
		if (!ret_val)
			return false;
		bit_shift -= 2;
	}
	return true;
}
