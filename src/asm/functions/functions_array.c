/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

static const asm_func_t asm_func[] = {
	{1, &live_asm},
	{2, &ld_asm},
	{3, &st_asm},
	{4, &add_asm},
	{5, &add_asm},
	{6, &and_asm},
	{7, &and_asm},
	{8, &and_asm},
	{9, &zjmp_asm},
	{10, &ldi_asm},
	{11, &sti_asm},
	{12, &fork_asm},
	{13, &lld_asm},
	{14, &lldi_asm},
	{15, &fork_asm},
	{16, &aff_asm},
	{0, NULL}
};


bool call_asm_functions(void)
{
	for (uint8_t i = 0; asm_func[i].func != NULL; i++);
	return true;
}
