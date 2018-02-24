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
	for (uint8_t i = 0; str[i] != '\0'; i++)
		write(fd, &str[i], 1);
	return true;
}

static bool write_name(int fd, char const *name)
{
	size_t len = my_strlen(name);

	write(fd, name, len);
	for (size_t i = 0; len + i < PROG_NAME_LENGTH; i++)
		write(fd, "\0", 1);
	return true;
}

static bool write_comment(int fd, char const *comment)
{
	size_t len = my_strlen(comment);

	write(fd, comment, len);
	for (size_t i = 0; len + i < COMMENT_LENGTH; i++)
		write(fd, "\0", 1);
	return true;
}

static bool write_prog_len(int fd)
{
	write(fd, "\0\0\0\0\0\0\0\0", 8);
	return true;
}

bool write_bytes(char *file, asm_t *asm_struct, char *hex)
{
	int fd = open(file, O_RDWR | O_CREAT, 0666);

	if (file == NULL)
		return false;
	else if (fd == -1)
		return false;
	if (write_magic(fd, hex) && write_name(fd, asm_struct->name) &&
	write_prog_len(fd) && write_comment(fd, asm_struct->comment)) {
		close(fd);
		return true;
	}
	close(fd);
	return false;
}
