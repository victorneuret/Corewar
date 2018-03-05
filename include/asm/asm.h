/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** asm header
*/

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include "common/op.h"
#include "common/str_split.h"
#include "common/utils/nbr/nbr_base.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/char/char_utils.h"
#include "common/utils/io/io_utils.h"
#include "common/my_printf.h"

#define SIZE_EXT 5

typedef struct {
	char **array;
	char *name;
	char *comment;
} asm_t;

void asm_help(void);
void check_file(asm_t *asm_struct);
char *conv_hex(int nb);
char **conv_file(char *buff);
bool check_syntax(asm_t *asm_s);
bool compile(char *file, asm_t *asm_struct);
bool write_bytes(char *file, asm_t *asm_struct);
