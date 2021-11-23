NAME	=	cub3d
PARSER	=	$(addprefix parser/, parser.c read_params.c read_map.c parse_map_line.c parser_utils.c get_color.c)
SRCS	=	${PARSER} main.c utils.c geometry.c hook.c init_vars.c util2.c util5.c
OBJS		=	$(SRCS:.c=.o)
FLAGS		=	-Wall -Wextra -Werror -g
LIBFTMAKE 	=	$(MAKE) -C libft/
CC			=	gcc

%.o: %.c
	cd $(@D) && $(CC) $(FLAGS) -c $(<F)

%.a %.dylib: FORCE
	$(MAKE) -C $(@D)

all: libft/libft.a  minilibx/libmlx.dylib $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) libft/libft.a -Lminilibx/ -lmlx
	install_name_tool -change libmlx.dylib minilibx/libmlx.dylib cub3d

FORCE:

clean:
	rm -f $(OBJS)
	$(LIBFTMAKE) clean
	$(MAKE) minilibx/ clean

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean
	$(MAKE) -C minilibx/ clean

re: fclean all

.PHONY:	all clean fclean re
