/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** String utils header
*/

#pragma once

#include <unistd.h>

void putstr(char const *str);
void puterr(char const *str);
int str_eq(char const *str1, char const *str2);
int my_strncmp(char const *s1, char const *s2, size_t n);
size_t my_strlen(char const *str);
