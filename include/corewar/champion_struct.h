/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** struct.h
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "common/op.h"

typedef struct token_list {
	unsigned int command;
	unsigned char args_type;
	int arg_one;
	int arg_two;
	int arg_three;
	unsigned int nb_bytes;
	struct token_list *next;
	struct token_list *prev;
} token_t;

typedef struct pc {
	uint64_t pc;
	struct pc *next;
} pc_t;

typedef struct champion_list {
	int nb_champion;
	int asm_token_len;
	char *asm_token;
	header_t header;
	token_t *token_list;
	uint32_t reg[REG_NUMBER];
	pc_t *pc;
	bool carry;
	uint16_t cycle_cmd;
	struct champion_list *next;
} champion_t;
