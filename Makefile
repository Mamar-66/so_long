NAME	=	so_long

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	srcs/
OBJ_PATH	=	objs/
LIBFT_PATH	=	./includes/libft/
MLX_PATH	=	./includes/minilibx-linux/
FT_PRINTF_PATH	=	./includes/printf/

LIBFT_FILE		=	libft.a
MLX_FILE		=	libmlx.a
FT_PRINTF_FILE	=	ft_printf.a

MLX_FLAG	=	-lX11 -lXext

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
LIBFT_LIB		=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
FT_PRINTF_LIB		=	$(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)
LIBFT_EX		=	$(LIBFT_LIB) $(CFLAGS)
FT_PRINTF_EX		=	$(FT_PRINTF_LIB) $(CFLAGS)

SRC	=	main.c \
\
		add_file_in_tab/file_in_tab.c \
\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
\
		errors/chr_elem.c \
		errors/print_error_comp.c \
		errors/chr_output_valid.c \
\
		graphique/creat_graph.c \
\
		utiles/dup_tab.c \

SRCS	=	$(addprefix $(SRC_PATH), $(SRC))

OBJ	= $(SRC:.c=.o)

OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))

INCS	=	-I	./includes/

all:	$(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
			mkdir $(OBJ_PATH)
			mkdir $(OBJ_PATH)/add_file_in_tab
			mkdir $(OBJ_PATH)/errors
			mkdir $(OBJ_PATH)/utiles
			mkdir $(OBJ_PATH)/get_next_line
			mkdir $(OBJ_PATH)/graphique

libft:
	@echo "\033[0;33m\nCOMPILING LIBFT$(LIBFT_PATH)\n"
	@make -sC $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING MLX$(MLX_PATH)\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

ft_printf:
	@echo "\033[0;33m\nCOMPILING FT_PRINTF$(FT_PRINTF_PATH)\n"
	@make -sC $(FT_PRINTF_PATH)
	@echo "\033[1;32mFT_PRINTF created\n"

$(NAME):	mlx libft ft_printf $(OBJS)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(CFLAGS) $(OBJS) $(MLX_EX) $(LIBFT_EX) $(FT_PRINTF_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
		rm -rf $(OBJ_PATH)
		make -sC $(LIBFT_PATH) clean
		make -sC $(MLX_PATH) clean
		make -sC $(FT_PRINTF_PATH) clean

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re