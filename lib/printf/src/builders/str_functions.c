/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** String formating
*/

#include "my_printf.h"

char *get_str(va_list args)
{
	char *result;
	char *temp;

	temp = va_arg(args, char*);
	if (temp)
		result = pf_strdup(temp);
	else
		result = pf_strdup("(null)");
	return (result);
}

char *get_clean_str(va_list args)
{
	char *result;
	char *temp;

	temp = va_arg(args, char*);
	if (temp)
		result = get_str_readable(temp);
	else
		result = pf_strdup("(null)");
	return (result);
}

char *pf_get_char(va_list args)
{
	char *result = pf_malloc(2, '\0');

	result[0] = va_arg(args, int);
	return (result);
}

char *pf_get_prct(void)
{
	char *result = pf_malloc(2, '\0');

	result[0] = '%';
	return (result);
}
