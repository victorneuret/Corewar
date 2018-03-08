/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_champion
*/

#pragma once

#include "corewar/corewar.h"
#include "corewar/champion_struct.h"

typedef struct {
	unsigned int id;
	void (*func)(token_t *token, champion_t *champ);
} exec_instruction_t;

bool exec_champ(champion_t *champ_list, vm_core_t *vm_core);
uint32_t indirect(int ind, champion_t *champ);
void copy_in_pc(const uint16_t pc, token_t *token, champion_t *champ,
	const uint8_t reg);

void exec_live(token_t *token, champion_t *champ);
void exec_ld(token_t *token, champion_t *champ);
void exec_st(token_t *token, champion_t *champ);
void exec_sti(token_t *token, champion_t *champ);
void exec_aff(token_t *token, champion_t *champ);
void nope(token_t *token, champion_t *champ);
