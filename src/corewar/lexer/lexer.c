/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** lexer
*/

#include "corewar/lexer/lexer.h"

static bool champion_comment(champion_t *new, int fd)
{
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	str[0] = '\0';
	read_size = read(fd, buffer, 1);
	for (int i = 1; read_size != 0 && i < PROG_NAME_LENGTH; i++) {
		str = check_letter_add(buffer[0], str);
		read_size = read(fd, buffer, 1);
	}
	new->comment = str;
	return true;
}

static bool champion_size(champion_t *new, int fd)
{
	char *buffer = malloc(sizeof(char) * 8);

	if (!buffer)
		return false;
	read(fd, buffer, 8);
	new->size = buffer;
	return true;
}

static bool champion_name(champion_t *new, int fd)
{
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	str[0] = '\0';
	read_size = read(fd, buffer, 1);
	for (int i = 1; read_size != 0 && i < PROG_NAME_LENGTH; i++) {
		str = check_letter_add(buffer[0], str);
		read_size = read(fd, buffer, 1);
	}
	new->champion_name = str;
	return true;
}

static bool exec_magic(champion_t *new, int fd)
{
	char buffer[4];
	new->exec_magic = malloc(sizeof(char) * 5);
	int j = 0;

	if (fd == -1 || !new->exec_magic)
		return false;
	for (int i = 0; i < 5; i++)
		new->exec_magic[i] = '\0';
	read(fd, buffer, 4);
	for (int i = 0; i < 4; i++)
		if (buffer[i] != '\0') {
			new->exec_magic[j] = buffer[i];
			j++;
		}
	return true;
}

champion_t *lexer(char *champion_path, champion_t *new)
{
	int fd = open(champion_path, O_RDONLY);

	if (fd == -1)
		return NULL;
	if (!exec_magic(new, fd) || !champion_name(new, fd))
		return NULL;
	if (!champion_size(new, fd) || !champion_comment(new, fd))
		return NULL;
	close(fd);
	return new;
}
