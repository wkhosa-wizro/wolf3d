NAME	= wolf3d

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

#LIBS	= -lm -lX11 -lXext -L minilibx_macos/ -lmlx

LIBS	= -L minilibx_macos/ -lmlx -lm -framework OpenGl -framework Appkit

INCLUDE	= ./include

SRC		=	main.c				\
			draw_walls.c		\
			draw_line.c			\
			image_manager.c		\
			event_handler.c		\

OBJ		=	main.o				\
			draw_walls.o		\
			draw_line.o			\
			image_manager.o		\
			event_handler.o		\

$(NAME):	$(OBJ)

$(OBJ):	$(INCLUDE)/wolf3d.h $(SRC)

all:	$(NAME)
$(NAME):
		make -C libft fclean && make -C libft && make -C minilibx_macos
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $(SRC)
		$(CC) $(CFLAGS) $(OBJ) -I libft/ $(LIBS) -L libft/ -lft -o $(NAME)

clean:
		rm -rfv $(OBJ)

fclean:	clean
		rm -rfv $(NAME)

re:	fclean all
