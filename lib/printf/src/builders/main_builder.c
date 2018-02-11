/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** String builder
*/

#include "my_printf.h"

static int get_result_length(char const *format, flag_list_t *head)
{
	int length = 0;
	flag_list_t *current = head;

	for (int i = 0; i < pf_strlen(format); i++) {
		while (format[i] != 0 && format[i] != '%') {
			i++;
			length++;
		}
		if (format[i] == 0)
			break;
		if (!current)
			continue;
		length += pf_strlen(current->formated) + 1;
		current = current->next;
	}
	return (length);
}

static int is_str_format(char specifier)
{
	switch (specifier) {
	case 's':
	case 'S':
	case 'c':
	case '%':
		return (1);
	default:
		return (0);
	}
}

static int is_nbr_format(char specifier)
{
	switch (specifier) {
	case 'd':
	case 'i':
	case 'b':
	case 'u':
	case 'o':
	case 'x':
	case 'X':
		return (1);
	default:
		return (0);
	}
}

char *pf_format(char const *flag, va_list args)
{
	char pf_last_character = pf_last_char(flag);
	char *result;

	if (is_str_format(pf_last_character))
		return (pf_build_str(flag, args));
	if (is_nbr_format(pf_last_character))
		return (pf_build_nbr(flag, args));
	if (pf_last_character == 'p')
		return (pf_get_hex(va_arg(args, unsigned long), "0x", 0));
	result = pf_malloc(pf_strlen(flag) + 2, '\0');
	result[0] = '%';
	for (int i = 1; i <= pf_strlen(flag); i++)
		result[i] = flag[i - 1];
	return (result);
}

char *pf_build(char const *format, flag_list_t *head)
{
	int format_i = 0;
	int result_i = 0;
	int result_length;
	char *result;
	flag_list_t *current = head;

	result_length = get_result_length(format, head);
	result = pf_malloc(result_length + 2, '\0');
	while (current) {
		while (format[format_i] != 0 && format[format_i] != '%')
			result[result_i++] = format[format_i++];
		if (format[format_i] == 0)
			break;
		format_i += pf_strlen(current->flag) + 1;
		for (int i = 0; i < pf_strlen(current->formated); i++)
			result[result_i++] = (current->formated)[i];
		current = current->next;
	}
	while (result_i < result_length)
		result[result_i++] = format[format_i++];
	return (result);
}
