/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** get_nb_len
*/

#include <stddef.h>

size_t get_nb_len(int nb)
{
	size_t length = 0;

	if (nb < 0)
		length++;
	if (nb == 0)
		return 1;
	while (nb != 0) {
		nb /= 10;
		length++;
	}
	return length;
}
