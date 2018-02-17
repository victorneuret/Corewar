##
## EPITECH PROJECT, 2018
## Corewar
## File description:
## Makefile
##

ASM	=	./asm/asm
CRW	=	./corewar

SRC_ASM	+=	$(shell find src/asm -name "*.c")
SRC_CRW	+=	$(shell find src/corewar -name "*.c")
SRC_COM += 	$(shell find src/common -name "*.c")

SRC_UNIT+=	$(shell find tests/unit_tests -name "*.c")

OBJ_ASM	+=	$(SRC_ASM:.c=.o)
OBJ_CRW	+=	$(SRC_CRW:.c=.o)
OBJ_COM +=	$(SRC_COM:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I include
CFLAGS	+=	-L lib -lprintf

all:		$(ASM) $(CRW)

%.o:		%.c
		@echo -e "[\e[34mcore\e[39m]\t : Compiling \e[94m$<\e[39m -> \e[92m$@\e[39m"
		@$(CC) -c $(CFLAGS) -o $@ $<

$(ASM):		lib $(OBJ_COM) $(OBJ_ASM)
		@$(CC) $(OBJ_ASM) $(OBJ_COM) $(CFLAGS) -o $(ASM)
		@echo -e "[\e[36masm\e[39m]\t : Compiled $(ASM)"

$(CRW):		lib $(OBJ_COM) $(OBJ_CRW)
		@$(CC) $(OBJ_CRW) $(OBJ_COM) $(CFLAGS) -o $(CRW)
		@echo -e "[\e[31mvm\e[39m]\t : Compiled $(CRW)"

clean_asm:
		@rm -f $(OBJ_ASM) $(OBJ_COM)
		@echo -e "[\e[36masm\e[39m]\t : Removed object files"

fclean_asm:	clean_asm
		@rm -f $(ASM)
		@echo -e "[\e[36masm\e[39m]\t : Removed binary file"

clean_crw:
		@rm -f $(OBJ_CRW) $(OBJ_COM)
		@echo -e "[\e[31mvm\e[39m]\t : Removed object files"

fclean_crw:	clean_crw
		@rm -f $(CRW)
		@echo -e "[\e[31mvm\e[39m]\t : Removed binary file"

clean:		clean_asm clean_crw

fclean:		fclean_asm fclean_crw
		@rm -f tests_run
		@make -C lib/printf --no-print-directory fclean

re:		fclean_lib fclean all
re_asm:		fclean_asm $(ASM)
re_crw:		fclean_crw $(CRW)

lib:
		@make -C lib/printf --no-print-directory
clean_lib:
		@make -C lib/printf --no-print-directory clean
fclean_lib:
		@make -C lib/printf --no-print-directory fclean
re_lib:
		@make -C lib/printf --no-print-directory re

valgrind:	lib
		@echo -en "Compiling debug binaries..."
		@$(CC) $(SRC_CRW) $(SRC_COM) $(CFLAGS) $(CFLAGS_CRW) -g3 -o $(CRW)
		@$(CC) $(SRC_ASM) $(SRC_COM) $(CFLAGS) $(CFLAGS_ASM) -g3 -o $(ASM)
		@echo -e " Done"

clean_coverage:
		@find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

tests_run:	lib
		@echo -en "Compiling debug binaries..."
		@$(CC) $(SRC_UNIT) $(SRC_COM) $(CFLAGS) $(CFLAGS_CRW) -g3 -o tests_run --coverage -lcriterion
		@echo -e " Done"
		./tests_run

.PHONY:		clean fclean				\
		clean_asm fclean_asm			\
		clean_crw fclean_crw			\
		re re_asm re_crw			\
		lib clean_lib fclean_lib re_lib		\
		tests_run clean_coverage		\
		valgrind
