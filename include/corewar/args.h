/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Argument header
*/

#pragma once

#include <stdint.h>

typedef struct {
	char *prog_path;
	int32_t prog_nb;
	int64_t load_addr;
} prog_t;

typedef struct {
	int64_t nbr_cycle;
	size_t champ_count;
	prog_t *programs;
} args_t;

bool champions_exist(args_t *args);
args_t *parse_arguments(char **av);
void free_args(args_t *args);
