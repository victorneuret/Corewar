/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** asm header
*/

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common/op.h"
#include "common/bool.h"
#include "common/str_split.h"
#include "common/utils/nbr/nbr_base.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/io/io_utils.h"
#include "common/bool.h"
#include "common/my_printf.h"

#define SIZE_EXT 5

typedef struct {
	char **array;
} asm_t;

void asm_help(void);
char *open_file(char *file);
void check_file(asm_t *asm_struct);
char **conv_file(char *buff);
int file_handling(char *file, asm_t *asm_struct);
char *conv_hex(int nb);
bool check_syntax(asm_t *asm_s);
int write_file(char *file, char *str);
