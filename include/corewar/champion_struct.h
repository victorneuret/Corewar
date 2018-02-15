/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** struct.h
*/

#pragma once

typedef struct token_list {
	unsigned int command;
	unsigned int args_type;
	int arg_one;
	int arg_two;
	int arg_three;
	unsigned int nb_bytes;
	struct token_list *next;
	struct token_list *prev;
} token_t;

typedef struct champion_list {
	int nb_champion;
	char *exec_magic;
	char *champion_name;
	char *size;
	char *comment;
	char *asm_token;
	token_t *token_list;
	struct champion_list *next;
} champion_t;
