/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM Main file
*/

#include "asm/asm.h"

static char *conv_filename(char *str)
{
	char *result = malloc(sizeof(str));

	my_strncpy(result, str, my_strlen(str));
	my_strncat(result, ".cor", 4);
	return (result);
}

char *open_file(char *file)
{
	int fd = open(file, O_RDONLY);
	char buff[1];
	char *str = malloc(sizeof(char));
	int size = 0;

	if (fd == -1)
		return (NULL);
	for (int i = 1; (size = read(fd, buff, 1)) != 0; i++) {
		if (size == -1)
			return (NULL);
		str = realloc(str, i);
		str[i - 1] = buff[0];
	}
	return (str);
}

int write_file(char *file, char *str)
{
	int fd = open(file, O_RDWR | O_CREAT, 0666);

	if (fd == -1)
		return 84;
	for (int i = 0; str[i] != '\0'; i++)
		write(fd, &str[i], 1);
	return (0);
}

void file_handling(char *file)
{
	char *str = NULL;

	str = open_file(file);
	if (!str) {
		puterr("Error: Can't open file\n");
		exit(84);
	}
	write_file(conv_filename(file), str);
	free(str);
}