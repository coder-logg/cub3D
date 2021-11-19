SRC =	ft_memset.c		ft_atoi.c		ft_bzero.c \
			ft_memccpy.c	ft_memchr.c		ft_memcmp.c \
			ft_memcpy.c		ft_memmove.c	ft_strchr.c \
			ft_strlcat.c	ft_strlcpy.c	ft_strlen.c \
			ft_strncmp.c	ft_strnstr.c	ft_strrchr.c \
			ft_calloc.c		ft_strdup.c		ft_isalnum.c \
			ft_isalpha.c	ft_isascii.c	ft_isdigit.c \
			ft_isprint.c	ft_strjoin.c	ft_substr.c \
			ft_tolower.c	ft_toupper.c	ft_strtrim.c \
			ft_split.c		ft_itoa.c		ft_strmapi.c \
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c \
			ft_putnbr_fd.c
OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))
NAME = $(LIBFT_PATH)/libft.a
INC = .
LIBFT_PATH = .
OBJ_PATH = .
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC)

.PHONY: clean fclean all re

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(OBJ_PATH)/%.c $(INC)/libft.h
	cc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all