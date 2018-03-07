/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** id
*/

#include "corewar/corewar.h"

static bool array_contains(int *array, int nb, size_t array_size)
{
	for (size_t i = 0; i < array_size; i++)
		if (array[i] == nb)
			return true;
	return false;
}

static bool contains_duplicates(int *array, size_t array_size)
{
	int save;

	for (size_t i = 0; i < array_size; i++) {
		save = array[i];
		array[i] = -2;
		if (save != 0 && array_contains(array, save, array_size))
			return true;
		array[i] = save;
	}
	return false;
}

bool attribute_ids(args_t *args)
{
	int ids[args->prog_ct];
	// int attribute_id = 1;

	for (size_t i = 0; i < args->prog_ct; i++)
		ids[i] = args->programs[i].prog_nb;
	if (contains_duplicates(ids, args->prog_ct)) {
		puterr("Duplicate IDs.\n");
		return false;
	}
	return true;
}
