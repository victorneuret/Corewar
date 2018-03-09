/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.h
*/

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint8_t id;
	bool (*func)();
} asm_func_t;

bool add_asm(void);
bool aff_asm(void);
bool and_asm(void);
bool fork_asm(void);
bool ld_asm(void);
bool ldi_asm(void);
bool live_asm(void);
bool lld_asm(void);
bool lldi_asm(void);
bool st_asm(void);
bool sti_asm(void);
bool zjmp_asm(void);
bool call_asm_functions(void);
