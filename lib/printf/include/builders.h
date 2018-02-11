/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Builders header
*/

#pragma once

char *pf_build_str(char const *flag, va_list args);
char *pf_build_nbr(char const *flag, va_list args);
char *pf_build(char const *format, flag_list_t *head);

char *pf_get_octal(unsigned long nbr, char *prefix);
char *pf_get_hex(unsigned long nbr, char *prefix, int upcase);

char *long_base(unsigned long nbr, char *base, char *prefix);
char *nbr_base(unsigned int nbr, char *base, char *prefix);
char *nbr_to_str(int i);

char *pf_format(char const *flag, va_list args);
char *get_str_readable(char const *str);

void pf_init_paddings(flag_list_t *head);
