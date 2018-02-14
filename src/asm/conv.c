/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Conv
*/

#include "asm/asm.h"


char *conv_hex(int nb)
{
	char *str = NULL;
	int len = 0;
	int tmp = nb;
	int i = 0;

	while ((tmp = tmp / 10) != 0)
		len++;
	str = malloc(sizeof(char) * len);
	tmp = nb;
	for (; tmp != 0; i++) {
		str[i] = tmp % 256;
		tmp = tmp / 256;
		str[i + 1] = '\0';
	}
	return (my_revstr(str));
}
