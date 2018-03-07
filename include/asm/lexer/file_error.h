/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file_error.h
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#include "asm/writter/file_writter.h"
#include "asm/lexer/syntax.h"
#include "asm/lexer/file.h"
#include "common/utils/io/io_utils.h"
#include "asm/asm_struct.h"

bool compile_error_handling(char *str, asm_t *asm_struct,
char *file_name, char *file);
