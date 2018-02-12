/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** ASM Main file
*/

#include "include/asm/asm.h"

void asm_help(void)
{
	putstr("USAGE\n\t./asm file_name[.s]\n");
	putstr("DESCRIPTION\n\tfile_name\tfile in assembly");
	putstr("language to be converted into file_name.cor, an\n");
	putstr("\t\t\texecutable in the Virtual Machine.\n");
	exit(0);
}