/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM hexa
*/

#include "asm/asm.h"

void write_file(char *str)
{
	int fd = open("file.cor", O_RDWR | O_CREAT, 0666);
	char c = '\0';

	for (int i = 0; str[i] != '\0'; i++) {
		c = str[i];
		write(fd, &c, 1);
		//write(fd, conv_hexa(str[i]), my_strlen(conv_hexa(str[i])));
	}
}

char *conv_hexa(int nb)
{
	char *result = malloc(sizeof(char) * 10);
	int temp = 0;
	int i = 0;

	for (; nb != 0; i++) {
		temp = nb % 16;
		if (temp < 10)
			result[i] = temp + 48;
		else
			result[i] = temp + 87;
		nb = nb / 16;
	}
	result[i] = '\0';
	return (my_revstr(result));
}
