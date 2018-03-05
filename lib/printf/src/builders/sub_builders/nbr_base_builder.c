/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** nbr base
*/

#include "my_printf.h"

static void nb_base_rec(unsigned long nb, char *base, char *result, int *index)
{
	int base_length = pf_strlen(base);

	if (nb >= (unsigned int) base_length)
		nb_base_rec(nb / base_length, base, result, index);
	result[*index] = base[nb % base_length];
	*index = *index + 1;
}

static int predict_length(unsigned long nbr, int base_length, char *prefix)
{
	int length = 0;

	if (prefix)
		length += pf_strlen(prefix);
	while (nbr >= (unsigned int) base_length) {
		nbr /= base_length;
		length++;
	}
	return (length + 1);
}

char *long_base(unsigned long nbr, char *base, char *prefix)
{
	int index = 0;
	int base_length = pf_strlen(base);
	int result_length = predict_length(nbr, base_length, prefix);
	char *result = pf_malloc(result_length + 1, '\0');

	if (nbr != 0 && prefix)
		for (; index < pf_strlen(prefix); index++)
			result[index] = prefix[index];
	if (nbr == 0)
		result[0] = base[0];
	if (nbr > 0)
		nb_base_rec(nbr, base, result, &index);
	return (result);
}

char *nbr_base(unsigned int nbr, char *base, char *prefix)
{
	return (long_base((unsigned long) nbr, base, prefix));
}
