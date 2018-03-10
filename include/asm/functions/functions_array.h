/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.h
*/

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include "asm/writter/parameters_writter.h"
#include "common/op.h"
#include "common/str_split.h"
#include "common/utils/str/str_utils.h"
#include "common/utils/nbr/getnbr.h"
#include "common/bit_manipulations.h"

typedef struct {
	uint8_t id;
	bool (*func)(int fd, char const *args, uint32_t *new_len);
} asm_func_t;

bool add_asm(int fd, char const *args, uint32_t *new_len);
bool aff_asm(int fd, char const *args, uint32_t *new_len);
bool and_asm(int fd, char const *args, uint32_t *new_len);
bool fork_asm(int fd, char const *args, uint32_t *new_len);
bool ld_asm(int fd, char const *args, uint32_t *new_len);
bool ldi_asm(int fd, char const *args, uint32_t *new_len);
bool live_asm(int fd, char const *args, uint32_t *new_len);
bool lld_asm(int fd, char const *args, uint32_t *new_len);
bool lldi_asm(int fd, char const *args, uint32_t *new_len);
bool st_asm(int fd, char const *args, uint32_t *new_len);
bool sti_asm(int fd, char const *args, uint32_t *new_len);
bool zjmp_asm(int fd, char const *args, uint32_t *new_len);
bool sub_asm(int fd, char const *args, uint32_t *new_len);
bool or_asm(int fd, char const *args, uint32_t *new_len);
bool xor_asm(int fd, char const *args, uint32_t *new_len);
bool lfork_asm(int fd, char const *args, uint32_t *new_len);

static const asm_func_t asm_func[] = {
	{1, &live_asm},
	{2, &ld_asm},
	{3, &st_asm},
	{4, &add_asm},
	{5, &sub_asm},
	{6, &and_asm},
	{7, &or_asm},
	{8, &xor_asm},
	{9, &zjmp_asm},
	{10, &ldi_asm},
	{11, &sti_asm},
	{12, &fork_asm},
	{13, &lld_asm},
	{14, &lldi_asm},
	{15, &lfork_asm},
	{16, &aff_asm},
	{0, NULL}
};
