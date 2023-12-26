NAME	=	so_long

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	srcs/
OBJ_PATH	=	objs/

MLX_FILE	=	libmlx.a

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRC	=	main.c

SRCS	=	$(addprefix $(SRC_PATH), $(SRC))

OBJ	= $(SRC:.c=.o)

OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))

INCS	=	-I	./includes/

all:	$(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
			mkdir $(OBJ_PATH)

mlx:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

$(NAME):	mlx $(OBJS)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(CFLAGS) $(OBJS) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
		rm -rf $(OBJ_PATH)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re