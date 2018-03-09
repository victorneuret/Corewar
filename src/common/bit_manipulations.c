/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** bit_manipulations
*/

int reverse_bits(int nb)
{
	return (((nb >> 24) & 0xff) | ((nb << 24) & 0xff000000) |
		((nb >> 8) & 0xff00) | ((nb << 8) & 0xff0000));
}

int reverse16_bits(int nb)
{
	return ((nb >> 8) & 0xff00) | ((nb << 8) & 0xff00);
}
