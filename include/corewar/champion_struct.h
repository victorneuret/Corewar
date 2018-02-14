/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** struct.h
*/

#pragma once

typedef struct token_list {
	char *token;
	struct token_list *next;
} token_t;

typedef struct champion_list {
	int nb_champion;
	char *exec_magic;
	char *champion_name;
	char *size;
	char *comment;
	char *asm_token;
	struct champion_list *next;
} champion_t;
