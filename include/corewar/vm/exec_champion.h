/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** exec_champion
*/

#pragma once

#include "corewar/corewar.h"
#include "corewar/champion_struct.h"
#include "corewar/parser/parser.h"

typedef struct {
	uint32_t id;
	void (*func)(token_t *token, champion_t *champ, vm_core_t *vm);
} exec_instruction_t;

bool exec_champ(champion_t *champ_list, vm_core_t *vm_core);
uint32_t indirect(int ind, champion_t *champ);
void copy_in_pc(const uint16_t pc, token_t *token, champion_t *champ,
	const uint8_t reg);
bool is_reg(uint8_t nb, uint8_t arg);

void exec_live(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_ld(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_st(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_add(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_sub(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_and(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_xor(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_or(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_zjmp(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_ldi(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_sti(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_lld(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_lldi(token_t *token, champion_t *champ, vm_core_t *vm);
void exec_aff(token_t *token, champion_t *champ, vm_core_t *vm);
void nope(token_t *token, champion_t *champ, vm_core_t *vm);
