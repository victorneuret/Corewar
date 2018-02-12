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

#include "common/op.h"
#include "common/bool.h"
#include "common/utils/str_utils.h"

typedef enum {
	NAME,
	COMMENT,
	ASM
} token_type;

typedef struct token_list {
	token_type type;
	char *token;
	struct token_list *next;
} token_t;

#include "corewar/lexer/champion_lexer.h"
#include "corewar/lexer/lexer_utils.h"

token_t *lexer(char *champion);
