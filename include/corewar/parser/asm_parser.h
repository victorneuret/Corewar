/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** asm_parser.h
*/

#pragma once

#include "common/bool.h"
#include "common/op.h"
#include "common/my_printf.h"
#include "corewar/champion_struct.h"

bool live_parser(token_t *token, char *asm_token, int *i);
bool ld_parser(token_t *token, char *asm_token, int *i);
bool st_parser(token_t *token, char *asm_token, int *i);
bool add_parser(token_t *token, char *asm_token, int *i);
bool and_parser(token_t *token, char *asm_token, int *i);
bool zjmp_parser(token_t *token, char *asm_token, int *i);
bool ldi_parser(token_t *token, char *asm_token, int *i);
bool sti_parser(token_t *token, char *asm_token, int *i);
bool fork_parser(token_t *token, char *asm_token, int *i);
bool lld_parser(token_t *token, char *asm_token, int *i);
bool lldi_parser(token_t *token, char *asm_token, int *i);
bool lfork_parser(token_t *token, char *asm_token, int *i);
bool aff_parser(token_t *token, char *asm_token, int *i);
