##
## EPITECH PROJECT, 2020
## PSU_minishell2_2019
## File description:
## Makefile
##

DIR	= 	./

LIB	=	$(DIR)str_in_str.c			\
		$(DIR)nbr.c					\
		$(DIR)str_to_word_array.c	\
		$(DIR)strs.c					\
		$(DIR)link_strs.c

CFLAGS = -Wall -Wextra

OBJ	=	$(LIB:.c=.o)

NAME	=	libllama.a

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)

debug:	CFLAGS += -g
debug:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(DIR)*.o

fclean: clean
	rm -f $(DIR)*.a

re:	fclean all