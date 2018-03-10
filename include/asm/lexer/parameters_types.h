/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Lexer file
*/

#pragma once

#include <stdint.h>
#include <stdlib.h>

#include "common/utils/nbr/getnbr.h"
#include "common/utils/str/str_utils.h"
#include "common/op.h"

#define TWO_BYTES_MAX_SIZE 0xffff
#define FOUR_BYTES_MAX_SIZE 0xffffffff

uint8_t check_arguments_types(char *arg, int j);
