/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** corewar.h
*/

#pragma once

#include <stdbool.h>

#include "common/my_printf.h"

#include "common/utils/io/io_utils.h"
#include "common/utils/str/str_utils.h"

#include "corewar/args.h"
#include "corewar/lexer/lexer.h"
#include "corewar/lexer/free_lexer.h"
#include "corewar/parser/parser.h"

champion_t *init_champ_list(prog_t *programs, champion_t *champ_list);
champion_t *init_champions(args_t *args, champion_t *champ_list);
