/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Number builder
*/

#include "my_printf.h"

static int has_prefix(char const *flag)
{
	for (int i = 0; i < pf_strlen(flag); i++)
		if (flag[i] == '#')
			return (1);
	return (0);
}

char *pf_get_octal(unsigned long nbr, char *prefix)
{
	char *result;
	char base08[] = "01234567";

	if (prefix)
		result = long_base(nbr, base08, prefix);
	else
		result = long_base(nbr, base08, 0);
	return (result);
}

char *pf_get_hex(unsigned long nbr, char *prefix, int upcase)
{
	char *result;
	char base16[] = "0123456789abcdef";

	if (prefix)
		result = long_base(nbr, base16, prefix);
	else
		result = long_base(nbr, base16, 0);
	if (upcase)
		result = pf_strupcase(result);
	return (result);
}

char *pf_build_nbr(char const *flg, va_list args)
{
	int upcase = 0;
	int int_arg = va_arg(args, unsigned int);

	switch (pf_last_char(flg)) {
	case 'd':
	case 'i':
		return nbr_to_str((int) int_arg);
	case 'b':
		return nbr_base(int_arg, "01", 0);
	case 'u':
		return nbr_base(int_arg, "0123456789", 0);
	case 'o':
		return pf_get_octal(int_arg, has_prefix(flg) ? "0" : 0);
	case 'X':
		upcase = 1;
		__attribute__((fallthrough));
	case 'x':
		return pf_get_hex(int_arg, has_prefix(flg) ? "0x" : 0, upcase);
	}
	return (0);
}
