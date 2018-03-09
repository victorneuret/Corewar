/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File writter
*/

#include "asm/writter/function_writter.h"

void write_byte(int fd, void *c)
{
	write(fd, &c, 1);
}

uint8_t bitwise(uint8_t b, uint8_t a)
{
	return ((b + a) << 2);
}

bool write_function(int fd, char const *line)
{
	if (!line)
		return (false);
	return (true);
}
