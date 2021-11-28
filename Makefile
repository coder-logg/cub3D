NAME	=	cub3d
PARSER	=	$(addprefix parser/, parser.c read_params.c read_map.c parse_map_line.c parser_utils.c get_color.c)
SRCS	=	${PARSER} main.c utils.c geometry.c hook.c init_vars.c util2.c util3.c util5.c
BSRCS	:= $(SRCS) create_hook_bonus.c
SRCS	+= create_hook.c
OBJS		=	$(SRCS:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
LIBFTMAKE 	=	$(MAKE) -C libft/
CC			=	gcc
LIBS	=	libft/libft.a  minilibx/libmlx.dylib

%.o: %.c
	cd $(@D) && $(CC) $(FLAGS) -c $(<F)

%.a %.dylib: FORCE
	$(MAKE) -C $(@D)

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) -o $(NAME) $^
	install_name_tool -change libmlx.dylib minilibx/libmlx.dylib $(NAME)

bonus: $(LIBS) $(BSRCS:.c=.o)
	$(CC) -o $(NAME) $^
	install_name_tool -change libmlx.dylib minilibx/libmlx.dylib $(NAME)

FORCE:

clean:
	rm -f $(BSRCS:.c=.o)
	$(LIBFTMAKE) clean
	$(MAKE) -C minilibx/ clean

fclean:
	rm -f $(NAME) $(BSRCS:.c=.o)
	$(LIBFTMAKE) fclean
	$(MAKE) -C minilibx/ clean

re: fclean all

.PHONY:	all clean fclean re
