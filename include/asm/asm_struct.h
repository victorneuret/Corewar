/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** asm struct
*/

#pragma once

typedef struct {
	char **array;
	char **labels;
	char *filename;
	char *executable;
	char *name;
	char *comment;
	int line;
} asm_t;
