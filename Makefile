##
## EPITECH PROJECT, 2018
## Corewar
## File description:
## Makefile
##

ASM	=	asm
CWR	=	corewar

SRC_ASM	+=	$(shell find src/asm -name "*.c")
SRC_CWR	+=	$(shell find src/corewar -name "*.c")
SRC_COM += 	$(shell find src/common -name "*.c")

OBJ_ASM	+=	$(SRC_ASM:.c=.o)
OBJ_CWR	+=	$(SRC_CWR:.c=.o)
OBJ_COM +=	$(SRC_COM:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I include/common

CFLAGS_ASM +=	-I include/asm

CFLAGS_CWR +=	-I include/corewar

all:		$(ASM) $(CWR)

%.o:		%.c
		@echo -e "[\e[34m$(CC)\e[39m] : Compiling \e[94m$<\e[39m -> \e[92m$@\e[39m"
		@$(CC) -c $(CFLAGS) -o $@ $<

$(ASM):		$(OBJ_COM) $(OBJ_ASM)
		@echo -en "Compiling $(ASM) ..."
		@$(CC) $(OBJ_ASM) $(OBJ_COM) $(CFLAGS) $(CFLAGS_ASM) -o $(ASM)
		@echo -e " Done"

$(CWR):		$(OBJ_COM) $(OBJ_CWR)
		@echo -en "Compiling $(CWR) ..."
		@$(CC) $(OBJ_CWR) $(OBJ_COM) $(CFLAGS) $(CFLAGS_CWR) -o $(CWR)
		@echo -e " Done"

clean:
		@echo -en "Cleaning object files..."
		@rm -f $(OBJ_ASM) $(OBJ_CWR) $(OBJ_COM)
		@echo -e " Done"

fclean:		clean
		@echo -en "FCleaning project..."
		@rm -f $(ASM) $(CWR)
		@echo -e " Done"

re:		fclean all

valgrind:
		@echo -en "Compiling debug binaries..."
		@$(CC) $(SRC_CWR) $(SRC_COM) $(CFLAGS) $(CFLAGS_CWR) -g3 -o $(CWR)
		@$(CC) $(SRC_ASM) $(SRC_COM) $(CFLAGS) $(CFLAGS_ASM) -g3 -o $(ASM)
		@echo -e " Done"

.PHONY:		all clean fclean re valgrind
