/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Argument management
*/

#include <stdlib.h>
#include <stdbool.h>

#include "common/op.h"
#include "common/utils/nbr/getnbr.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/array/array_utils.h"

#include "corewar/args.h"

static void init_prog(prog_t *prog)
{
	prog->prog_nb = 0;
	prog->prog_path = 0;
	prog->load_addr = 0;
}

static bool is_option_managed(char **av, args_t *args,
			prog_t *progs, size_t *index)
{
	if (str_eq(av[*index], "-dump")) {
		*index += 1;
		return true;
	}
	if (str_eq(av[*index], "-a")) {
		*index += 1;
		progs[args->prog_ct - 1].load_addr = getnbr(av[*index]);
		return true;
	}
	if (str_eq(av[*index], "-n")) {
		*index += 1;
		progs[args->prog_ct - 1].prog_nb = getnbr(av[*index]);
		return true;
	}
	return false;
}

static prog_t *get_programs(args_t *args, char **av)
{
	prog_t *progs = malloc(sizeof(prog_t));

	if (!progs)
		return 0;
	init_prog(&progs[args->prog_ct - 1]);
	for (size_t i = 1; av && av[i]; i++) {
		if (!progs)
			return 0;
		if (is_option_managed(av, args, progs, &i))
			continue;
		progs[args->prog_ct - 1].prog_path = my_strdup(av[i]);
		progs = realloc(progs, sizeof(prog_t) * ++args->prog_ct);
		init_prog(&progs[args->prog_ct - 1]);
	}
	return progs;
}

args_t *parse_arguments(char **av)
{
	args_t *args = malloc(sizeof(args_t));

	if (!args)
		return 0;
	args->prog_ct = 1;
	args->nbr_cycle = get_or_default(av, "-dump", CYCLE_TO_DIE);
	args->programs = get_programs(args, av);
	args->prog_ct -= 1;
	if (!args->programs) {
		free(args);
		return 0;
	}
	return args;
}

void free_args(args_t *args)
{
	if (!args)
		return;
	for (size_t i = 0; i < args->prog_ct; i++)
		free(args->programs[i].prog_path);
	free(args->programs);
	free(args);
}
