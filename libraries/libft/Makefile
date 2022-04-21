NAME =		libft.a

CC =		gcc

CFLAGS = -c \
		-Wall \
		-Werror \
		-Wextra \

AR		= ar
ARFLAGS	= rc

OBJ_DIR	= ./obj
SRC_DIR	= ./src

RM		= rm -rf


SRC	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c
SRC	+=	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
SRC	+=	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c
SRC	+=	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c
SRC	+=	ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_split.c
SRC	+=	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC	+=	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c
SRC	+=	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
SRC	+=	ft_tolower.c ft_toupper.c ft_count_digit.c ft_free_ptr.c
SRC	+=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c
SRC	+=	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
SRC	+=	ft_lstiter.c ft_lstmap.c

OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR):
		mkdir -p ./obj

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
