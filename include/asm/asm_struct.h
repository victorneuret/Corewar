/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** asm struct
*/

#pragma once

#include <sys/types.h>
#include <stdint.h>

typedef struct {
	char **array;
	char **labels;
	char *filename;
	char *executable;
	char *name;
	char *comment;
	int line;
} asm_t;

typedef struct {
	char *label;
	off_t offset;
	uint16_t label_call;
	uint16_t label_define;
} label_t;
