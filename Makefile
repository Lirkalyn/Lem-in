##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	main.c \
		src/display/begin_display.c \
		src/display.c \
		src/algo/input.c \
		src/algo/filler.c \
		src/algo/rooms.c \
		src/algo/rooms_2.c \
		src/algo/rooms_3.c \
		src/algo/tunnel.c \
		src/algo/tunnel_2.c \
		src/algo/tunnel_3.c \
		src/algo/tunnel_4.c \
		src/algo/ant.c \
		src/display/displayer.c \
		src/pathfinding/check.c \
		src/pathfinding/start_a.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
