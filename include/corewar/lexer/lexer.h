/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** lexer.h
*/

#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "common/op.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/nbr/nbr_base.h"

#include "corewar/champion_struct.h"
#include "corewar/lexer/lexer_utils.h"
#include "corewar/lexer/lexer_asm.h"
#include "corewar/champion_struct.h"
#include "corewar/parser/parser_utils.h"

champion_t *lexer(char *champion_path, champion_t *new);
