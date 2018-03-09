/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** functions_array.c
*/

#include "asm/functions/functions_array.h"

bool call_asm_functions(void)
{
	for (uint8_t i = 0; asm_func[i].func != NULL; i++);
	return true;
}
