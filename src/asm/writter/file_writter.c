/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** File writter
*/

#include "asm/asm.h"

#include "common/bit_manipulations.h"

static bool write_header(int fd, asm_t *asm_s)
{
	header_t header = {0};

	for (size_t i = 0; i <= PROG_NAME_LENGTH; i++)
		header.prog_name[i] = '\0';
	for (size_t i = 0; i <= COMMENT_LENGTH; i++)
		header.comment[i] = '\0';
	header.magic = reverse_bits(COREWAR_EXEC_MAGIC);
	header.prog_size = 0xaaaaaaaa;
	my_strncpy(header.prog_name, asm_s->name, my_strlen(asm_s->name));
	my_strncpy(header.comment, asm_s->comment, my_strlen(asm_s->comment));
	write(fd, &header, sizeof(header_t));
	return true;
}

bool write_bytes(char *file, asm_t *asm_s)
{
	int fd = open(file, O_RDWR | O_CREAT, 0666);

	if (file == NULL || fd == -1)
		return false;
	if (write_header(fd, asm_s)) {
		close(fd);
		return true;
	}
	close(fd);
	return false;
}
