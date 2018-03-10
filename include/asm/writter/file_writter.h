/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Writter file_writter
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "asm/asm_struct.h"
#include "common/bit_manipulations.h"
#include "common/utils/str/str_utils.h"
#include "common/op.h"

bool write_bytes(char *file, asm_t *asm_struct);
bool write_function(int fd, asm_t *asm_s, uint32_t *new_len);
