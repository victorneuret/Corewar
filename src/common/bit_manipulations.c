/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** bit_manipulations
*/

int reverse_bits(int nb)
{
	return (((nb >> 24) & 0xff) | ((nb << 24) & 0xff000000) |
		((nb >> 8) & 0xff00) | ((nb << 8) & 0xff0000));
}