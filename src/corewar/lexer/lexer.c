/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** lexer
*/

#include "corewar/lexer/lexer.h"

static bool champion_comment(champion_t *new, int const fd)
{
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	str[0] = '\0';
	read_size = read(fd, buffer, 1);
	if (read_size == -1)
		return false;
	for (int i = 1; read_size != 0 && i < COMMENT_LENGTH; i++) {
		str = check_letter_add(buffer[0], str);
		read_size = read(fd, buffer, 1);
		if (read_size == -1)
			return false;
	}
	new->comment = str;
	return true;
}

static bool champion_size(champion_t *new, int const fd)
{
	char *buffer = malloc(sizeof(char) * 8);

	if (!buffer)
		return false;
	if (read(fd, buffer, 8) == -1)
		return false;
	new->size = buffer;
	return true;
}

static bool champion_name(champion_t *new, int const fd)
{
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	str[0] = '\0';
	read_size = read(fd, buffer, 1);
	if (read_size == -1)
		return false;
	for (int i = 1; read_size != 0 && i < PROG_NAME_LENGTH; i++) {
		str = check_letter_add(buffer[0], str);
		read_size = read(fd, buffer, 1);
		if (read_size == -1)
			return false;
	}
	new->champion_name = str;
	return true;
}

static bool exec_magic(int const fd)
{
	char buffer[4];
	char *exec_magic = malloc(sizeof(char) * 5);
	int j = 0;

	if (fd == -1 || !exec_magic)
		return false;
	for (int i = 0; i < 5; i++)
		exec_magic[i] = '\0';
	if (read(fd, buffer, 4) == -1)
		return false;
	for (int i = 0; i < 4; i++)
		if (buffer[i] != '\0') {
			exec_magic[j] = buffer[i];
			j++;
		}
	free(exec_magic);
	return true;
}

champion_t *lexer(char *champion_path, champion_t *new)
{
	int fd = open(champion_path, O_RDONLY);

	if (fd == -1) {
		free(new);
		return NULL;
	}
	if (!exec_magic(fd) || !champion_name(new, fd)
		|| !champion_size(new, fd) || !champion_comment(new, fd))
		return NULL;
	champion_lexer(new, fd);
	close(fd);
	return new;
}
