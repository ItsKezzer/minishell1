##
## EPITECH PROJECT, 2020
## PSU_minishell2_2019
## File description:
## Makefile
##

INC_DIR	=	./inc/
SRC_DIR	=	./src/
LIB_DIR	=	./lib/

SRC	=	$(SRC_DIR)main.c		\
		$(SRC_DIR)get_env.c		\
		$(SRC_DIR)minishell.c	\
		$(SRC_DIR)execute.c		\
		$(SRC_DIR)no_env.c		\
		$(SRC_DIR)built_ins.c	\
		$(SRC_DIR)clean_str.c	\
		$(SRC_DIR)exit.c		\
		$(SRC_DIR)pipe_handling.c

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -Werror -I./inc/ -I./lib/

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L $(LIB_DIR) -lllama

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(SRC_DIR)*.o
	rm -f $(LIB_DIR)*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)*.a
	
tests_run:	clean

re: fclean all
