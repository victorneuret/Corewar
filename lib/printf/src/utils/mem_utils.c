/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Memory functions
*/

#include "my_printf.h"

void *pf_malloc(unsigned int size, char init)
{
	char *ptr = malloc(size + 1);

	if (!ptr)
		return (0);
	for (unsigned int i = 0; i <= size; i++)
		*(ptr + i) = init;
	return (ptr);
}
