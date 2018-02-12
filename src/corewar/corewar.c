/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Corewar Main file
*/

#include "common/bool.h"
#include "common/my_printf.h"

#include "common/utils/io_utils.h"
#include "common/utils/str_utils.h"
#include "corewar/lexer/lexer.h"

int main(void)
{
	my_printf("Hello %s!\n", "world");
	lexer("../Corewar_files/binaires-champ-corewar/corewar/assets/champions/abel.cor");
	return 0;
}
