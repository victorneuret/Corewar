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
#include "common/op.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"

char **parse_line(char *line);
bool check_good_parameters(int code, int nb);
