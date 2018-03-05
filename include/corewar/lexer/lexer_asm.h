/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** lexer_asm.h
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "corewar/champion_struct.h"
#include "corewar/lexer/lexer_utils.h"

bool champion_lexer(champion_t *new, int fd);
