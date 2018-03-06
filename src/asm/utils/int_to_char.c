/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Conv int_to_char
*/

#include "asm/utils/int_to_char.h"

char *int_to_char(int nb)
{
	char *str;
	int tmp = nb;
	int i = 0;

	if (tmp == 0)
		i = 1;
	for (i = 0; tmp > 0; i++) {
		tmp = tmp / 10;
	}
	str = malloc(sizeof(char) * (i + 1));
	tmp = nb;
	if (tmp == 0) {
		str[i] = '0';
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		str[j] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	str[i] = '\0';
	return (str);
}
