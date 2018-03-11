/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Writter function_writter
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

#include "asm/asm_struct.h"
#include "common/bit_manipulations.h"
#include "asm/parser/parser.h"
#include "asm/lexer/function_syntax.h"

void write_labels(int fd, label_t *label_s);
