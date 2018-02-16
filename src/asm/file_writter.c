/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** File writter
*/

#include "asm/asm.h"

static bool write_magic(int fd, char *str)
{
	for (size_t i = my_strlen(str); i < 4; i++)
		write(fd, "\0", 1);
	for (int i = 0; str[i] != '\0'; i++)
		write(fd, &str[i], 1);
	return true;
}

bool write_bytes(char *file, char *hex)
{
	int fd = open(file, O_RDWR | O_CREAT, 0666);

	if (file == NULL)
		return false;
	else if (fd == -1)
		return false;
	if (write_magic(fd, hex)) {
		close(fd);
		return true;
	}
	close(fd);
	return false;
}
