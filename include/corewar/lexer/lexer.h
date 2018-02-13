/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** lexer.h
*/

#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "common/op.h"
#include "common/bool.h"
#include "common/utils/str_utils.h"
#include "common/utils/nbr_base.h"

#include "corewar/champion_struct.h"
#include "corewar/lexer/lexer_utils.h"
#include "corewar/lexer/lexer_asm.h"
#include "corewar/champion_struct.h"

champion_t *lexer(char *champion_path, champion_t *new);
