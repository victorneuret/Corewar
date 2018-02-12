/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"
#include "corewar/lexer/lexer.h"

static int print_help(void)
{
	char buffer[16384];
	int fd = open("README.txt", O_RDONLY);

	for (size_t i = 0; i < 16384; i++)
		buffer[i] = 0;
	if (fd == -1)
		return 84;
	read(fd, buffer, 16384);
	putstr(buffer);
	close(fd);
	return 0;
}

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		if (str_eq(av[i], "-h"))
			return print_help();
	my_printf("Hello %s!\n", "world");
	lexer("../Corewar_files/binaires-champ-corewar/"
		"corewar/assets/champions/abel.cor");
	return 0;
}
