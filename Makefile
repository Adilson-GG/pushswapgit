CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_PATH = sources/

OBJ_PATH = objets/

SRC = push_swap.c ft_swap.c ft_push.c ft_reverse_r.c ft_rotate.c ft_errors.c algo.c\
	compare_str.c annexe.c pivot.c

OBJ = $(SRC:.c=.o)

OBJ_DIR = objets

SRC_DIR = sources

PREFC = $(addprefix $(SRC_PATH), $(SRC))

PREFO = $(addprefix $(OBJ_PATH), $(OBJ))

all : $(NAME)


$(NAME) : $(PREFO)
	@make -s -C libft all
	@$(CC) $(CFLAGS)  -o $(NAME) $(PREFO)  libft/libft.a -g3
	@echo "Compilation terminee !"


$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean
	@echo "------->  Au revoir les .o."

fclean : clean
	@rm -f $(NAME) libft.a
	@make -s -C libft fclean
	@echo "--------> Tout est a la poubelle, chef !"

re : fclean all

.PHONY : all clean fclean re