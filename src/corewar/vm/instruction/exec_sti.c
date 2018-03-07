/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_sti
*/

#include "corewar/vm/exec_champion.h"

static uint8_t get_param_sti(token_t *token, uint8_t index)
{
	uint8_t size = 0;

	my_printf("index: %d\n", index);
	if (token->args_type == 0 || token->command == 0x10 || index == 2)
		return 1;
	switch ((token->args_type >> 6) & 3) {
	case 1: size = 1; break;
	case 2: size = IND_SIZE; break;
	case 3: size = DIR_SIZE; break;
	}
	if (index == 2 + size)
		return 2;
	return 3;

}

static void copy_in_pc(const uint16_t pc, token_t *token, champion_t *champ,
	const uint8_t reg)
{
	uint16_t index = 0;
	token_t *tmp = champ->token_list;

	for (; tmp && index + tmp->nb_bytes <= pc - token->nb_bytes;
		index += tmp->nb_bytes) {
		tmp = tmp->next;
	}
	if (pc - token->nb_bytes == index)
		tmp->command = reg;
	else if ((pc - (uint8_t) token->nb_bytes == index + 1)
		&& token->args_type != 0)
		tmp->args_type = reg;
	else {
		switch (get_param_sti(token,
			(pc - token->nb_bytes) - index - 1)) {
		case 1: tmp->arg_one = reg; break;
		case 2: tmp->arg_two = reg; break;
		case 3: tmp->arg_three = reg; break;
		}
	}
}

void exec_sti(token_t *token, champion_t *champ)
{
	uint8_t bit_shift = 6;
	uint8_t mask = 3;
	uint16_t value = 0;

	switch ((token->args_type >> (bit_shift - 2)) & mask) {
	case 1: value += champ->reg[token->arg_two - 1]; break;
	case 2: value += (int16_t) token->arg_two; break;
	case 3: value += (int16_t) token->arg_two; break;
	}
	switch ((token->args_type >> (bit_shift - 4)) & mask) {
	case 1: value += champ->reg[token->arg_three - 1]; break;
	case 2: value += (int16_t) token->arg_three; break;
	}
	copy_in_pc(champ->pc->pc + value % IDX_MOD, token, champ,
		champ->reg[token->arg_one - 1]);
}
