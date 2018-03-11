/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Writter function_writter
*/

#pragma once

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

#include "asm/asm_struct.h"
#include "common/utils/str/str_utils.h"
void free_struct(label_t *label_s, size_t label_count);
void insert_label_call(bool bytes, const char *label, uint32_t call,
label_t *label_s);
void insert_label_define(uint32_t *new_len, label_t *label_s);
void init_labels(label_t *label_s, asm_t *asm_s);
