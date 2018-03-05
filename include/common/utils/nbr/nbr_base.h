/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** Nbr base header
*/

#pragma once

#include <stdlib.h>

#define BASE_BIN "01"
#define BASE_OCT "01234567"
#define BASE_DEC "0123456789"
#define BASE_HEX "0123456789abcdef"

#define BASE_HEX_CAPS "0123456789ABCDEF"

char *conv_nb_base(size_t nb, char const *base);
