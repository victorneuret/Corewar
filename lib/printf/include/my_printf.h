/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Header
*/

#pragma once

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include "str_utils.h"
#include "flag_list.h"
#include "builders.h"
#include "mem_utils.h"
#include "char_utils.h"
#include "str_functions.h"
#include "getnbr.h"

#define ABS(x) (x > 0 ? (x) : -(x))

int my_printf(const char *format, ...);
