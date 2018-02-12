/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** String utils header
*/

#pragma once

#include <unistd.h>

char *my_revstr(char *str);
int str_eq(char const *str1, char const *str2);
size_t my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncat(char *dest, char const *to_add, size_t n);
