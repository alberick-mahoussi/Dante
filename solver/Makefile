##
## EPITECH PROJECT, 2022
## make =file
## File description:
## builder
##

SRC	=	graph_management.c	\
		file_reader.c	\
		memory_relaser.c	\
		path_administration.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
