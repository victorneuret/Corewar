/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** chamion lexer
*/

#include "corewar/lexer/champion_lexer.h"

static bool init_lexer_list(token_t *token_list, token_type type)
{
	if (!token_list)
		return false;
	token_list->type = type;
	token_list->next = NULL;
	return true;
}

static char *add_string(char c, char *str)
{
	char *ptr;

	if (str[0] == '\0') {
		str[0] = c;
		str[1] = '\0';
		return str;
	}
	ptr = malloc(sizeof(char) * (my_strlen(str) + 2));
	if (!ptr)
		return NULL;
	for (unsigned int i = 0; i < my_strlen(str) + 2; i++)
		ptr[i] = '\0';
	for (int i = 0; str[i] != '\0'; i++) {
		ptr[i] = str[i];
		ptr[i + 1] = c;
	}
	free(str);
	return ptr;
}

static char *check_letter_add(char c, char *str)
{
	if (c >= 20 && c <= 126)
		str = add_string(c, str);
	if (!str)
		return NULL;
	return str;
}

token_t *champion_name(char *champion)
{
	token_t* token_list = malloc(sizeof(token_t));
	int fd = open(champion, O_RDONLY);
	char buffer[1];
	int read_size = 0;
	char *str = malloc(sizeof(char) * 2);

	if (fd == -1 || !init_lexer_list(token_list, NAME) || !str)
		return NULL;
	str[0] = '\0';
	read_size = read(fd, buffer, 1);
	for (int i = 1; read_size != 0 && i < PROG_NAME_LENGTH; i++) {
		str = check_letter_add(buffer[0], str);
		read_size = read(fd, buffer, 1);
	}
	close(fd);
	token_list->token = str;
	return token_list;
}
