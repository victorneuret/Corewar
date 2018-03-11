/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File writter
*/

#include "asm/writter/function_writter.h"

void write_byte(int fd, void *c)
{
	write(fd, &c, 1);
}

bool call_function(int fd, char **line, uint32_t *new_len,
__attribute__((unused)) label_t *label_s)
{
	int8_t code = 0;

	code = function_exists(line[0]);
	if (code != -1 && line[1] != NULL) {
		asm_func[code].func(fd, line[1], new_len);
		if (line)
			free_str_array(line);
		return true;
	}
	return false;
}

bool check_function_label(int fd, char **line, uint32_t *new_len,
label_t *label_s)
{
	if (is_label(line[0])) {
		if (line[1])
			line[1] = clean_str(line[1]);
		line = parse_line(line[1]);
		if (!line)
			return false;
		insert_label_define(new_len, label_s);
		if (!call_function(fd, line, new_len, label_s))
			return false;
	}
	return true;
}


bool get_arguments(int fd, asm_t *asm_s, uint32_t *new_len)
{
	char **line = NULL;
	size_t label_count = count_args(asm_s->labels);
	label_t *label_s = malloc(sizeof(label_t) * label_count);

	if (!label_s)
		return false;
	init_labels(label_s, asm_s);
	for (int i = 0; asm_s->array[i]; i++) {
		line = parse_line(asm_s->array[i]);
		if (!line) {
			free_struct(label_s, label_count);
			return false;
		}
		if (call_function(fd, line, new_len, label_s))
			continue;
		else
			check_function_label(fd, line, new_len, label_s);
		free_str_array(line);
	}
	free_struct(label_s, label_count);
	return true;
}

bool write_function(int fd, asm_t *asm_s,uint32_t *new_len)
{
	if (!get_arguments(fd, asm_s, new_len))
		return false;
	return (true);
}
