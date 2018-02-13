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

#include "common/utils/str_utils.h"
#include "common/utils/io_utils.h"
#include "common/bool.h"
#include "common/my_printf.h"

#define SIZE_EXTENSION 4

typedef struct {
	int lines;
	char **array;
} asm_t;

char *conv_hexa(int nb);
void asm_help(void);
int write_file(char *file, char *str);
char *open_file(char *file);
void check_file(asm_t *asm_struct);
char **conv_file(char *buff);
int file_handling(char *file, asm_t *asm_struct);
