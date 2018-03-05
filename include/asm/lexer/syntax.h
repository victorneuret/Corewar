/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Lexer syntax
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

#include "asm/asm_struct.h"
#include "common/op.h"
#include "common/utils/str/str_utils.h"
#include "common/my_printf.h"
#include "common/str_split.h"

bool check_syntax(asm_t *asm_s);
