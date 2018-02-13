/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Input/Output utils
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common/utils/io/io_utils.h"
#include "common/utils/str/str_utils.h"

int print_file_content(char const *path)
{
	char buffer[HELPS_READ_SIZE];
	int fd = open(path, O_RDONLY);

	for (size_t i = 0; i < 16384; i++)
		buffer[i] = 0;
	if (fd == -1)
		return 84;
	read(fd, buffer, 16384);
	putstr(buffer);
	close(fd);
	return 0;
}

void putstr(char const *str)
{
	write(1, str, my_strlen(str));
}

void puterr(char const *str)
{
	write(2, str, my_strlen(str));
}
