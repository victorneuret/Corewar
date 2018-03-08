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
	uint64_t load_addr;
} prog_t;

typedef struct {
	int8_t nbr_cycle;
	size_t prog_ct;
	prog_t *programs;
} args_t;

args_t *parse_arguments(char **av);
void free_args(args_t *args);
