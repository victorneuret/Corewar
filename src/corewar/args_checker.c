/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** args_checker
*/

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common/utils/str/str_utils.h"

#include "corewar/args.h"
#include "common/my_printf.h"

bool champions_exist(args_t *args)
{
	int fd;

	for (size_t i = 0; i < args->champ_count; i++) {
		fd = open(args->programs[i].prog_path, O_RDONLY);
		if (fd == -1) {
			my_printf("Cannot load champion %s\n",
					args->programs[i].prog_path);
			return false;
		}
		close(fd);
	}
	return true;
}
