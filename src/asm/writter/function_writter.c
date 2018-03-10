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

bool get_arguments(int fd, asm_t *asm_s)
{
	char **line = NULL;
	int code = 0;

	for (int i = 0; asm_s->array[i] != NULL; i++) {
		line = parse_line(asm_s->array[i]);
		if (!line)
			return false;
		code = function_exists(line[0]);
		if (code != -1 && line[1] != NULL) {
			asm_func[code].func(fd, line[1]);
			free_str_array(line);
			continue;
		}
		free_str_array(line);
	}
	return true;
}

bool write_function(int fd, asm_t *asm_s)
{
	if (!get_arguments(fd, asm_s))
		return false;
	return (true);
}
