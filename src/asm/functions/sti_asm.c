/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool sti_asm(__attribute__((unused)) int fd)
{
	uint8_t i = 11;

	write(fd, &i, sizeof(uint8_t));
	return true;
}
