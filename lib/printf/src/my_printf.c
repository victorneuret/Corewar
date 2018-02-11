/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Main file
*/

#include "my_printf.h"

static char *get_flag(char const *str)
{
	int end;
	int i = 0;
	char *result;

	if (str[i] == ' ' && str[i + 1] == ' ')
		while (str[++i] == ' ');
	if (str[i] == ' ')
		i++;
	end = i;
	if (str[end] != '%')
		while (pf_is_flag_end(str[++i]) && pf_is_specifier(str[i]))
			end++;
	if (str[end] == '%') {
		result = pf_malloc(2, '\0');
		result[0] = '%';
	} else {
		result = pf_substring(str, 0, end);
	}
	return (result);
}

static void parse_string(char const *str, flag_list_t *head)
{
	int flag_length;
	char *current_flag = pf_malloc(1, 0);
	flag_list_t *current = head;
	flag_list_t *previous;

	for (int i = 0; i < pf_strlen(str); i++) {
		if (str[i] != '%')
			continue;
		free(current_flag);
		current_flag = get_flag(str + i + 1);
		flag_length = pf_strlen(current_flag);
		if (flag_length == 1 && current_flag[0] == ' ')
			continue;
		current->flag = pf_strdup(current_flag);
		current->next = pf_malloc(sizeof(flag_list_t), 0);
		previous = current;
		current = current->next;
		i += flag_length;
	}
	free(current_flag);
	pf_rm_last_element(previous);
}

static void format_flags(flag_list_t *head, va_list args)
{
	flag_list_t *current = head;

	while (current) {
		current->formated = pf_format(current->flag, args);
		current = current->next;
	}
}

static int write_and_free(char *str)
{
	int length = pf_strlen(str);

	write(1, str, length);
	free(str);
	return (length);
}

int my_printf(const char *format, ...)
{
	va_list args;
	char *result;
	int result_length;
	flag_list_t *head = pf_malloc(sizeof(flag_list_t), 0);

	if (!head)
		return (0);
	if (!pf_contains_specifiers(format)) {
		write(1, format, pf_strlen(format));
		free(head);
		return (0);
	}
	va_start(args, format);
	parse_string(format, head);
	format_flags(head, args);
	pf_init_paddings(head);
	result = pf_build(format, head);
	result_length = write_and_free(result);
	va_end(args);
	pf_free_list(head);
	return (result_length);
}
