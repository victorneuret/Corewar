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

#include "asm/writter/function_writter.h"
#include "common/utils/nbr/getnbr.h"
#include "common/utils/str/str_utils.h"
#include "common/bit_manipulations.h"

typedef struct {
	uint8_t id;
	bool (*func)(int fd);
} asm_func_t;

bool add_asm(int fd, char const *args);
bool aff_asm(int fd, char const *args);
bool and_asm(int fd, char const *args);
bool fork_asm(int fd, char const *args);
bool ld_asm(int fd, char const *args);
bool ldi_asm(int fd, char const *args);
bool live_asm(int fd, char const *args);
bool lld_asm(int fd, char const *args);
bool lldi_asm(int fd, char const *args);
bool st_asm(int fd, char const *args);
bool sti_asm(int fd, char const *args);
bool zjmp_asm(int fd, char const *args);
bool sub_asm(int fd, char const *args);
bool or_asm(int fd, char const *args);
bool xor_asm(int fd, char const *args);
bool lfork_asm(int fd, char const *args);
bool call_asm_functions(void);
