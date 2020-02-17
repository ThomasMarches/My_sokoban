##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		= 	src/main.c \
			src/move_p.c \
			src/my_strcpy.c \
			src/get_actual_line_char.c \
			src/check_defeat.c \
			src/checking_size.c \
			src/bool_win.c \
			src/check_error.c \
			src/fill_map.c \
			src/print_my_map.c \
			src/my_strlen.c \
			src/show_read_me.c \
			src/handle_double_string.c \
			src/handle_o.c \
			src/init_struct.c \

NAME	= my_sokoban

OBJ	=	$(SRC:.c=.o)

LFLAGS +=	-l ncurses

CFLAGS += -W -Wall -Wextra -pedantic -I./Include

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
		rm -f lib/my/*.o
		rm -f src/*.o
		rm -f *.gc*
		rm -f a.out

fclean: clean
		rm -f $(NAME)
		rm -f lib/my/libmy.a

re: fclean all