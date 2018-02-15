/*
** EPITECH PROJECT, 2018
** Corewar
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

bool champion_lexer(champion_t *new, int fd)
{
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	str[0] = '\0';
	do {
		read_size = read(fd, buffer, 1);
		if (read_size == -1)
			return false;
	} while (buffer[0] == '\0');
	while (read_size != 0) {
		str = add_null_string_char(buffer[0], str, new->asm_token_len);
		if (!str)
			return false;
		read_size = read(fd, buffer, 1);
		if (read_size == -1)
			return false;
		new->asm_token_len++;
	}
	new->asm_token = str;
	return true;
}
