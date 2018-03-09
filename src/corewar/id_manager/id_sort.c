/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** id_sort
*/

#include "corewar/corewar.h"

static void swap_progs(prog_t *p1, prog_t *p2)
{
	prog_t save = *p1;

	*p1 = *p2;
	*p2 = save;
}

static bool is_prog_list_sorted(args_t *args)
{
	for (size_t i = 0; i + 1 < args->prog_ct; i++)
		if (args->programs[i].prog_nb >
		args->programs[i + 1].prog_nb)
			return false;
	return true;
}

static void sort(args_t *args)
{
	for (size_t i = 0; i + 1 < args->prog_ct; i++) {
		if (args->programs[i].prog_nb >
		args->programs[i + 1].prog_nb) {
			swap_progs(&args->programs[i], &args->programs[i + 1]);
		}
	}
}

bool sort_programs(args_t *args)
{
	while (!is_prog_list_sorted(args))
		sort(args);
	return true;
}
