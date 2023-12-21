NAME	=	so_long

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC_PATH	=	srcs/
OBJ_PATH	=	objs/

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

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJ_PATH)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re