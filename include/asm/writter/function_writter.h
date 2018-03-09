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

#include "asm/functions/functions_array.h"
#include "asm/asm_struct.h"
#include "asm/parser/parser.h"
#include "asm/lexer/function_syntax.h"

bool get_arguments(asm_t *asm_s);
bool write_function(int fd, char const *line);
uint8_t bitwise(uint8_t b, uint8_t a);
void write_zero(int fd);
