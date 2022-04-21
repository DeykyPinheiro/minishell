NAME = minishell

LIBFT_PATH = ./libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a

CC =	gcc
CFLAGS	= -Wall \
		-Werror \
		-Wextra

LFLAGS =	-lreadline \
			-L \
			$(LIBFT_PATH) \
			-lft

vpath %.c src 						\
		src/builtin 				\
		src/parser 					\
		src/signal 					\


SRC =  ft_cd.c \
		test2.c \
		test.c

RM = rm -rf

OBJ_DIR = obj

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

r: all
	./$(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
