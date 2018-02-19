/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** parer.h
*/

#pragma once

#include <stdlib.h>

#include "common/bool.h"
#include "common/op.h"
#include "corewar/champion_struct.h"
#include "corewar/parser/asm_parser.h"

typedef struct {
	int id;
	bool (*func)(token_t *token, char *asm_token, int *i);
} asm_parser_t;

bool parser(champion_t *champ);
