/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** lexer_asm.h
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>

#include "corewar/champion_struct.h"
#include "common/bool.h"
#include "corewar/lexer/lexer_utils.h"

bool champion_lexer(champion_t *new, int fd);
