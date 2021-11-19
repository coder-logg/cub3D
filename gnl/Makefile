SRC =	get_next_line_utils.c get_next_line.c
OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))
NAME = libgnl.a
INC = .
PATH = .
OBJ_PATH = .
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC)

.PHONY: clean fclean all re

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(OBJ_PATH)/%.c $(INC)/libgnl.h
	cc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all