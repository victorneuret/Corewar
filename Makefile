##
## EPITECH PROJECT, 2018
## Corewar
## File description:
## Makefile
##

ASM	=	asm
CRW	=	corewar

SRC_ASM	+=	$(shell find src/asm -name "*.c")
SRC_CRW	+=	$(shell find src/corewar -name "*.c")
SRC_COM += 	$(shell find src/common -name "*.c")

OBJ_ASM	+=	$(SRC_ASM:.c=.o)
OBJ_CRW	+=	$(SRC_CRW:.c=.o)
OBJ_COM +=	$(SRC_COM:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I include

all:		$(ASM) $(CRW)

%.o:		%.c
		@echo -e "[\e[34mcorewar\e[39m] : Compiling \e[94m$<\e[39m -> \e[92m$@\e[39m"
		@$(CC) -c $(CFLAGS) -o $@ $<

$(ASM):		$(OBJ_COM) $(OBJ_ASM)
		@echo -en "Compiling $(ASM) ..."
		@$(CC) $(OBJ_ASM) $(OBJ_COM) $(CFLAGS) -o $(ASM)
		@echo -e " Done"

$(CRW):		$(OBJ_COM) $(OBJ_CRW)
		@echo -en "Compiling $(CRW) ..."
		@$(CC) $(OBJ_CRW) $(OBJ_COM) $(CFLAGS) -o $(CRW)
		@echo -e " Done"

clean_asm:
		@echo -en "Cleaning asm object files..."
		@rm -f $(OBJ_ASM) $(OBJ_COM)
		@echo -e " Done"

fclean_asm:	clean_asm
		@echo -en "FCleaning asm..."
		@rm -f $(ASM)
		@echo -e " Done"

clean_crw:
		@echo -en "Cleaning corewar object files..."
		@rm -f $(OBJ_CRW) $(OBJ_COM)
		@echo -e " Done"

fclean_crw:	clean_crw
		@echo -en "FCleaning corewar..."
		@rm -f $(CRW)
		@echo -e " Done"

clean:		clean_asm clean_crw
fclean:		fclean_asm fclean_crw

re:		fclean all
re_asm:		fclean_asm $(ASM)
re_crw:		fclean_crw $(CRW)

valgrind:
		@echo -en "Compiling debug binaries..."
		@$(CC) $(SRC_CRW) $(SRC_COM) $(CFLAGS) $(CFLAGS_CRW) -g3 -o $(CRW)
		@$(CC) $(SRC_ASM) $(SRC_COM) $(CFLAGS) $(CFLAGS_ASM) -g3 -o $(ASM)
		@echo -e " Done"

.PHONY:		clean_asm fclean_asm clean_crw fclean_crw clean fclean re re_asm re_crw valgrind
