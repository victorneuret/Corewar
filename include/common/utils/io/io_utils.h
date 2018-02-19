/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** Input/Output utils header
*/

#pragma once

#include "common/bool.h"

#define HELP_READ_SIZE 16384

void putstr(char const *str);
void puterr(char const *str);
bool print_file_bytes(char const *path);
