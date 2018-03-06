/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Parser parser
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "asm/asm_struct.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"

bool parse_function(asm_t *asm_struct);
char **parse_comment(char *line);
