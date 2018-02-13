/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** asm header
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
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

char *conv_hexa(int nb);
void asm_help(void);
int write_file(char *file, char *str);
char *open_file(char *file);
int file_handling(char *file);
void check_file(char *str);
char **conv_file(char *buff);
