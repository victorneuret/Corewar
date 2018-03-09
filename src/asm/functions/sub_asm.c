/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool sub_asm(int fd, char const *args)
{
	uint8_t i = 5;

	write(fd, &i, sizeof(uint8_t));
	return true;
}
