NAME =	libft.a
SRCS = 	ft_isprint.c		ft_strlen.c		ft_memchr.c\
		ft_isdigit.c		ft_strlcpy.c	ft_memcmp.c\
		ft_isalnum.c		ft_strncmp.c	ft_memcpy.c\
		ft_isalpha.c		ft_tolower.c	ft_memset.c\
		ft_isascii.c		ft_toupper.c	ft_memccpy.c\
		ft_bzero.c			ft_strchr.c		ft_strrchr.c\
		ft_atoi.c			ft_strchr.c		ft_strlcat.c\
		ft_calloc.c			ft_strdup.c		ft_itoa.c\
		ft_memmove.c		ft_strnstr.c	ft_substr.c\
		ft_putchar_fd.c		ft_putstr_fd.c	ft_putendl_fd.c\
		ft_putnbr_fd.c		ft_strmapi.c	ft_strjoin.c\
		ft_split.c			ft_strtrim.c	ft_strcpy.c \
		ft_strcmp.c			ft_lstnew.c		ft_lstsize.c \
		ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c\
		ft_lstadd_front.c	ft_lstiter.c	ft_lstlast.c \
		get_next_line.c		max_min.c		ft_lstmap.c

RM		=	rm -f
OBJS	=	$(SRCS:.c=.o)
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

%.o: %.c
	$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:  clean
		$(RM) $(NAME)

re:   fclean $(NAME)

.PHONY: all clean fclean re
