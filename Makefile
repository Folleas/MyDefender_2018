##
## EPITECH PROJECT, 2018
## My_runner
## File description:
## My_runner's makefile
##

SRCDIR  =       src

INCDIR =	include

SRC     =       $(SRCDIR)/main_loop.c \
                $(SRCDIR)/main.c \
                $(SRCDIR)/manage_object.c \
                $(SRCDIR)/manage_buttons.c \
                $(SRCDIR)/move_functions.c \
                $(SRCDIR)/menu.c \
                $(SRCDIR)/pause.c \
                $(SRCDIR)/game.c \
                $(SRCDIR)/init.c \
                $(SRCDIR)/general.c \
                $(SRCDIR)/general2.c \
                $(SRCDIR)/manage_mouse.c \
                $(SRCDIR)/manage_enemy.c \
                $(SRCDIR)/towers.c \
                $(SRCDIR)/end_game.c \
                $(SRCDIR)/setup.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_defender

CFLAGS  =       -W -Wall -Wextra -I include/

GFLAGS =        -lcsfml-window -lcsfml-graphics -lcsfml-system

all:            $(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) $(GFLAGS) -g3 -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

