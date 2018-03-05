/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** String utils header
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>

/* str_utils_1.c */
char *my_revstr(char *str);
int str_eq(char const *str1, char const *str2);
size_t my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncat(char *dest, char const *to_add, size_t n);

/* str_utils_2.c */
char *my_strdup(char const *src);
char *my_strncpy(char *dest, const char *src, size_t n);
bool ends_with(char const *str, char const *suffix);
char *substring(char const *src, size_t begin, size_t end);
