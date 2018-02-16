/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Conv
*/

#include "asm/asm.h"

static char *zero_hex(void)
{
	char *str = malloc(2);

	if (!str)
		return 0;
	str[0] = 0;
	str[1] = 0;
	return str;
}

char *conv_hex(int nb)
{
	char *str = NULL;
	int len = 0;
	int tmp = nb;
	int i = 0;

	if (nb == 0)
		return zero_hex();
	while ((tmp = tmp / 10) != 0)
		len++;
	str = malloc(sizeof(char) * len);
	if (!str)
		return NULL;
	tmp = nb;
	for (; tmp != 0; i++) {
		str[i] = tmp % 256;
		tmp = tmp / 256;
		str[i + 1] = '\0';
	}
	return (my_revstr(str));
}
