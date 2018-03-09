/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** CPE_corewar_2017.h
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "common/my_printf.h"

#include "common/utils/io/io_utils.h"
#include "common/utils/str/str_utils.h"
#include "common/bit_manipulations.h"

#include "corewar/id.h"
#include "corewar/args.h"
#include "corewar/champion_struct.h"
#include "corewar/lexer/lexer.h"
#include "corewar/lexer/free_lexer.h"

typedef struct vm {
	uint64_t cycle;
	uint64_t cycle_to_die;
	uint64_t nb_live;
	uint8_t last_alive;
	uint8_t memory[MEM_SIZE];
	char *champ_name;
	bool alive;
} vm_core_t;

#include "corewar/parser/parser.h"
#include "corewar/vm/exec_champion.h"

champion_t *init_champions(args_t *args, champion_t *champ_list);
vm_core_t *init_vm_core(void);
bool init_memory(champion_t *champ_list, vm_core_t *vm_core, args_t *arg);
