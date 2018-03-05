/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** String to nbr
*/

#include "my_printf.h"

static int is_neg_number(char const *str)
{
	int count = 0;

	for (int i = 0; i < pf_strlen(str); i++)
		if (str[i] == '-')
			count++;
	return (count % 2 == 1);
}

static int is_overflow(unsigned int nbr, int is_neg)
{
	if ((!is_neg && nbr > 2147483647) || (is_neg && nbr > 2147483648))
		return (1);
	else
		return (0);
}

static int ret_nbr(int start, int end, unsigned long nbr, char const *str)
{
	int nbr_return;
	int is_neg;

	if (end - start >= 9)
		if (str[start] >= '4')
			return (0);
	if (end - start > 9)
		return (0);
	for (int i = start; i <= end; i++) {
		nbr *= 10;
		nbr += (str[i] - '0');
	}
	nbr_return = nbr;
	is_neg = is_neg_number(str);
	if (is_overflow(nbr_return, is_neg))
		return (0);
	if (is_neg)
		nbr_return = -nbr;
	return (nbr_return);
}

int pf_getnbr(char const *str)
{
	unsigned long nbr = 0;
	int length = pf_strlen(str);
	int start = -1;
	int end = -1;

	for (int i = 0; i < length; i++) {
		if (str[i] >= '0' && str[i] <= '9' && start < 0)
			start = i;
		if ((str[i] < '0' || str[i] > '9') && start >= 0) {
			end = i - 1;
			break;
		}
	}
	if (start < 0)
		return (0);
	if (end < 0)
		end = length - 1;
	return (ret_nbr(start, end, nbr, str));
}
