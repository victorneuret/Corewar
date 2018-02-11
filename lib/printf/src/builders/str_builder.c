/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Builds string related specifiers
*/

#include "my_printf.h"

static int readable_strlen(char const *str)
{
	int length = 0;

	for (int i = 0; i < pf_strlen(str); i++) {
		if (str[i] > 31)
			length += 1;
		else
			length += 4;
	}
	return (length);
}

static char *str_convert(char to_convert)
{
	char *dest = pf_malloc(4, 0);
	char *octal = pf_get_octal(to_convert, 0);
	int oct_length = pf_strlen(octal);

	dest[0] = '\\';
	dest[1] = '0';
	if (oct_length == 1) {
		dest[2] = '0';
		dest[3] = octal[0];
	} else {
		dest[2] = octal[0];
		dest[3] = octal[1];
	}
	free(octal);
	return (dest);
}

char *get_str_readable(char const *str)
{
	int newstr_index = 0;
	int length = readable_strlen(str);
	char *result = pf_malloc(length + 1, '\0');
	char *dest = 0;

	for (int i = 0; i < pf_strlen(str); i++) {
		if (str[i] > 31) {
			result[newstr_index++] = str[i];
		} else {
			dest = str_convert(str[i]);
			result[newstr_index + 0] = dest[0];
			result[newstr_index + 1] = dest[1];
			result[newstr_index + 2] = dest[2];
			result[newstr_index + 3] = dest[3];
			newstr_index += 4;
			free(dest);
		}
	}
	result[length] = 0;
	return (result);
}

char *pf_build_str(char const *flag, va_list args)
{
	char *result = 0;

	switch (pf_last_char(flag)) {
	case 's':
		return (get_str(args));
	case 'S':
		return (get_clean_str(args));
	case 'c':
		return (pf_get_char(args));
	case '%':
		return (pf_get_prct());
	}
	return (result);
}
