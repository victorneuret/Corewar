/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** File writter
*/

#include "asm/writter/write_byte.h"

void write_byte(int fd, void *c)
{
	write(fd, &c, 1);
}

static void reverse_bytes(int fd, label_t *label_s, int32_t size, size_t i)
{
	if (label_s[i].bytes) {
		size = reverse16_bits(size);
		write(fd, &size, sizeof(int16_t));
	} else {
		size = reverse_bits(size);
		write(fd, &size, sizeof(int32_t));
		}
}

void write_labels(int fd, label_t *label_s)
{
	int32_t size = 0;

	for (size_t i = 0; label_s[i].label; i++) {
		if (label_s[i].label_call == 0)
			continue;
		for (size_t j = 0; j < label_s[i].calls; j++) {
			size = label_s[i].label_define -
			label_s[i].label_call[j] + 1;
			lseek(fd, 0x890 + label_s[i].label_call[j], SEEK_SET);
			reverse_bytes(fd, label_s, size, i);
		}
	}
}
