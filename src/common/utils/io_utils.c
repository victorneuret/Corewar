/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Input/Output utils
*/

#include <unistd.h>

#include "common/utils/str_utils.h"

void putstr(char const *str)
{
	write(1, str, my_strlen(str));
}

void puterr(char const *str)
{
	write(2, str, my_strlen(str));
}
