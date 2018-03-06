/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Lexer function_syntax
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

#include "asm/asm_struct.h"
#include "asm/parser/parser.h"
#include "asm/lexer/syntax.h"
#include "asm/utils/int_to_char.h"
#include "common/utils/io/io_utils.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"
#include "common/my_printf.h"
#include "common/str_split.h"
#include "common/op.h"

bool check_function(char *line, asm_t *asm_s);
