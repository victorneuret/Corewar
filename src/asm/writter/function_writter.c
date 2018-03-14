/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File writter
*/

#include "asm/writter/function_writter.h"

bool call_function(int fd, char **line, uint32_t *new_len, label_t *label_s)
{
	int8_t code = 0;

	code = function_exists(line[0]);
	if (code != -1 && line[1] != NULL) {
		asm_func[code].func(fd, line[1], new_len, label_s);
		return true;
	}
	return false;
}

static int8_t exec_is_label(int fd, char **line, uint32_t *new_len,
label_t *label_s)
{
	char **str = NULL;

	insert_label_define(new_len, label_s);
	if (line[1]) {
		str = parse_line(line[1]);
		if (!str)
			return -1;
		if (!call_function(fd, str, new_len, label_s)) {
			free_str_array(str);
			return -1;
		}
		free_str_array(str);
		return 0;
	}
	return 1;
}

bool check_function_label(int fd, char **line, uint32_t *new_len,
label_t *label_s)
{
	if (is_label(line[0])) {
		if (exec_is_label(fd, line, new_len, label_s) == -1)
			return false;
	}
	return true;
}

bool get_arguments(int fd, asm_t *asm_s, uint32_t *new_len, label_t *label_s)
{
	char **line = NULL;

	if (!label_s)
		return false;
	init_labels(label_s, asm_s);
	for (int i = 0; asm_s->array[i]; i++) {
		line = parse_line(asm_s->array[i]);
		if (!line)
			return false;
		if (call_function(fd, line, new_len, label_s)) {
			free_str_array(line);
			continue;
		}
		else
			check_function_label(fd, line, new_len, label_s);
		free_str_array(line);
	}
	return true;
}

bool write_function(int fd, asm_t *asm_s, uint32_t *new_len)
{
	size_t label_count = count_args(asm_s->labels);
	label_t *label_s = malloc(sizeof(label_t) * (label_count + 1));

	if (!get_arguments(fd, asm_s, new_len, label_s)) {
		free_struct(label_s, label_count);
		return false;
	}
	write_labels(fd, label_s);
	free_struct(label_s, label_count);
	return (true);
}
