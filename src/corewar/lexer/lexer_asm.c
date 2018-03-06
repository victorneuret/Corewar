/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** lexer for compiled asm
*/

#include "corewar/lexer/lexer_asm.h"

static char *add_null_string_char(char const c, char *str, int size)
{
	char *ptr;

	if (size == 0) {
		str[0] = c;
		str[1] = '\0';
		return str;
	}
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return NULL;
	for (int i = 0; i < size; i++)
		ptr[i] = str[i];
	ptr[size] = c;
	free(str);
	return ptr;
}

static bool read_header_pass(int fd)
{
	header_t header = {0};

	if (read(fd, &header, sizeof(header)) <= 0)
		return false;
	return true;
}

static bool read_asm(int fd, char *str, champion_t *new)
{
	char buffer;
	int read_size = 0;

	do {
		read_size = read(fd, &buffer, 1);
		if (read_size == -1)
			return false;
	} while (buffer == '\0');
	while (read_size != 0) {
		str = add_null_string_char(buffer, str, new->asm_token_len);
		if (!str)
			return false;
		read_size = read(fd, &buffer, 1);
		if (read_size == -1)
			return false;
		new->asm_token_len++;
	}
	new->asm_token = str;
	return true;
}

bool champion_lexer(champion_t *new, int fd)
{
	char *str = malloc(sizeof(char) * 2);

	if (!str || !read_header_pass(fd))
		return false;
	str[0] = '\0';
	if (!read_asm(fd, str, new))
		return false;
	return true;
}
