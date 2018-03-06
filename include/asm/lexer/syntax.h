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
#include "asm/parser/parser.h"
#include "asm/utils/int_to_char.h"
#include "common/utils/io/io_utils.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"
#include "common/my_printf.h"
#include "common/str_split.h"
#include "common/op.h"

/* COLORS */
#define BLUE "\033[1;36m"
#define WHITE "\033[1;37m"
#define NC "\x1b[0m"

bool check_syntax(asm_t *asm_s);
