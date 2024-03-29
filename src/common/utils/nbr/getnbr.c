/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** send string return number
*/

#include "common/utils/nbr/getnbr.h"

int64_t getnbr(char const *str)
{
	int64_t nb = 0;
	int j = 0;

	if (!str)
		return 0;
	for (int i = 0; str[i] != '\0'; i++) {
		for (j = j; str[i] == '+' || str[i] == '-'; i++)
			(str[i] == '-') ? j++ : 0;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9') {
			(j % 2 == 1) ? nb = nb * -1 : 0;
			return nb;
		}
	}
	if (j % 2 == 1)
		nb *= -1;
	return nb;
}
