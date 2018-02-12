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

char *conv_hexa(int nb);
void asm_help(void);
void write_file(char *str);
