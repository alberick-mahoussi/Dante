##
## EPITECH PROJECT, 2022
## makefile
## File description:
## builder
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		my_strcmp.c	\
		gen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

