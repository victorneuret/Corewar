/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Argument header
*/

#pragma once

typedef struct {
	char *prog_path;
	int prog_nb;
	unsigned long load_addr;
} prog_t;

typedef struct {
	int nbr_cycle;
	size_t prog_ct;
	prog_t *programs;
} args_t;

args_t *parse_arguments(char **av);
void free_args(args_t *args);
