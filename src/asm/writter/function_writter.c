/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File writter
*/

#include "asm/writter/function_writter.h"

bool get_arguments(asm_t *asm_s)
{
	char **line = NULL;
	int8_t code = 0;

	for (int i = 0; asm_s->array[i] != NULL; i++) {
		line = parse_line(asm_s->array[i]);
		if (!line || line[1] == NULL)
			return false;
		code = function_exists(line[0]);
		if (code != -1)
			asm_func[code].func(line[1]);
		free_str_array(line);
	}
	return true;
}

void write_zero(int fd)
{
	char c = 0;

	write(fd, &c, 1);
}

uint8_t bitwise(uint8_t b, uint8_t a)
{
	return ((b + a) << 2);
}

bool write_function(__attribute__((unused)) int fd, char const *line)
{
	if (!line)
		return (false);
	return (true);
}
