/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Writter parameters_writter
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

#include "common/op.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/nbr/getnbr.h"
#include "common/bit_manipulations.h"

uint32_t get_arg_value(char const *arg, uint8_t code);
uint8_t get_arg_size(char const *arg);
size_t get_arg_bytes(uint8_t code, int32_t *value, uint32_t *new_len,
uint8_t function);
uint8_t bitwise(uint8_t b, uint8_t a);
void write_function_value(int fd, uint8_t i, char **array);
