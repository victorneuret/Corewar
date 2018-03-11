/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Lexer file
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "asm/writter/file_writter.h"
#include "asm/lexer/file_error.h"
#include "asm/lexer/syntax.h"
#include "asm/parser/parser.h"
#include "common/op.h"
#include "common/utils/char/char_utils.h"
#include "common/utils/io/io_utils.h"
#include "asm/asm_struct.h"

#define SIZE_EXT 5

bool compile(char *file, asm_t *asm_struct);
char *open_file(char *file);
char *conv_filename(char *str);
void fill_struct(asm_t *asm_struct);

#define BINARY_EXTENSION ".cor"
