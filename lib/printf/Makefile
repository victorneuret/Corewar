##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## Makefile
##

NAME=		../libprintf.a

INCLUDE=	./include

SRC=		$(shell find ./src -name '*.c')

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
		@echo -e "[\e[33mprintf\e[39m] : Compiling \e[94m$<\e[39m -> \e[92m$@\e[39m"
		@$(CC) -I$(INCLUDE) -c $(CFLAGS) -o $@ $<

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo -e "[\e[33mprintf\e[39m] : Library built"

clean:
		@rm -rf $(OBJ) $(UNIT_OBJ)
		@echo -e "[\e[33mprintf\e[39m] : Removed object files"

fclean:		clean
		@rm -rf $(NAME)
		@echo -e "[\e[33mprintf\e[39m] : Removed library"

re:		fclean all

.PHONY:		all clean fclean re
