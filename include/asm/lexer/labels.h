/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** labels.h
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "asm/asm_struct.h"
#include "asm/lexer/syntax.h"
#include "asm/utils/clean_str.h"

bool check_labels(asm_t *asm_s);
bool check_label_line(char **str, asm_t *asm_s);
bool is_valid_label_name(char const *line);
