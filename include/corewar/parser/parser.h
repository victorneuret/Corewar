/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** parer.h
*/

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "common/op.h"
#include "corewar/champion_struct.h"
#include "corewar/parser/asm_parser.h"
#include "corewar/corewar.h"

typedef struct {
	int8_t id;
	bool (*func)(token_t *token, uint8_t *asm_token, int i);
} asm_parser_t;

bool parser(champion_t *champ);
void print_token(token_t *token);
void print_token_list(token_t *head);
bool parser_next_instruction(champion_t *champ, vm_core_t *vm);
