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

typedef struct {
	uint8_t id;
	bool (*func)(int fd);
} asm_func_t;

bool add_asm(__attribute__((unused)) int fd);
bool aff_asm(__attribute__((unused)) int fd);
bool and_asm(__attribute__((unused)) int fd);
bool fork_asm(__attribute__((unused)) int fd);
bool ld_asm(__attribute__((unused)) int fd);
bool ldi_asm(__attribute__((unused)) int fd);
bool live_asm(__attribute__((unused)) int fd);
bool lld_asm(__attribute__((unused)) int fd);
bool lldi_asm(__attribute__((unused)) int fd);
bool st_asm(__attribute__((unused)) int fd);
bool sti_asm(__attribute__((unused)) int fd);
bool zjmp_asm(__attribute__((unused)) int fd);
bool sub_asm(__attribute__((unused)) int fd);
bool or_asm(__attribute__((unused)) int fd);
bool xor_asm(__attribute__((unused)) int fd);
bool lfork_asm(__attribute__((unused)) int fd);
bool call_asm_functions(void);
