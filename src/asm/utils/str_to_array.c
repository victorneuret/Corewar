/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** str_to_array.c
*/

#include "asm/utils/str_to_array.h"

static int count_lines(char *buff)
{
	int lines = 0;

	if (buff == NULL)
		return (0);
	for (int i = 0; buff[i] != '\0'; i++)
		if (buff[i] == '\n')
			lines += 1;
	return (lines + 1);
}

static int next_line(char *buff, int nb)
{
	for (; buff[nb] != '\n' && buff[nb] != '\0'; nb++);
	return (nb);
}

char **conv_file(char *buff)
{
	char **str;
	int columns = 0;
	int j = 0;
	int k = 0;

	str = malloc(sizeof(char*) * (count_lines(buff) + 1));
	if (!str)
		return (NULL);
	for (int i = 0; i < count_lines(buff); i++) {
		columns = next_line(buff, k);
		str[i] = malloc(sizeof(char) * (columns + 1));
		if (!str[i])
			return (NULL);
		for (j = 0; buff[k] != '\n' && buff[k] != '\0'; j++)
			str[i][j] = buff[k++];
		str[i][j] = '\0';
		k++;
	}
	str[count_lines(buff)] = 0;
	return (str);
}
