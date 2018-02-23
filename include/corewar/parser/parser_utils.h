/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** parser_utils.h
*/

#pragma once

#include <stdlib.h>
#include <stdbool.h>

#include "corewar/champion_struct.h"
#include "common/op.h"
#include "common/my_printf.h"
#include "common/utils/str/str_utils.h"

#define ABS_CHAR(x) (x < 0 ? x + 256 : x)

bool asm_arg_parser(token_t *token, char *asm_token, int *i);
bool asm_arg_register(token_t *token, char *asm_token, int k, int *i);
bool asm_arg_direct(token_t *token, char *asm_token, int k, int *i);
bool asm_arg_indirect(token_t *token, char *asm_token, int k, int *i);

void init_token(token_t *token);
bool is_index_needed(token_t *token);
