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

bool print_file_bytes(char const *path)
{
	char buffer[2];
	int fd = open(path, O_RDONLY);

	if (fd == -1)
		return false;
	while (read(fd, buffer, 1) > 0) {
		buffer[1] = '\0';
		putstr(buffer);
	}
	close(fd);
	return true;
}

void putstr(char const *str)
{
	write(1, str, my_strlen(str));
}

void puterr(char const *str)
{
	write(2, str, my_strlen(str));
}
