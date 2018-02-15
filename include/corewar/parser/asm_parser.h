/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** asm_parser.h
*/

#pragma once

#include "common/bool.h"
#include "common/op.h"
#include "corewar/champion_struct.h"

bool live_parser(token_t *token, char *asm_token, int *i);
bool ld_parser(token_t *token, char *asm_token, int *i);
