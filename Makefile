NAME	=	cub3D
PARSER	=	$(addprefix parser/, parser.c read_params.c read_map.c parse_map_line.c parser_utils.c get_color.c)
GRAPHIC_DIR	=	graphic
GRAPHIC	=	$(addprefix ${GRAPHIC_DIR}/, main.c utils.c geometry.c hook.c init_vars.c util2.c util3.c util5.c)
SRCS	= 	${PARSER} ${GRAPHIC}
NOBONUS	=	${GRAPHIC_DIR}/create_hook.c
BONUS	:=	${GRAPHIC_DIR}/create_hook_bonus.c
OBJS		=	$(SRCS:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
LIBFTMAKE 	=	$(MAKE) -C libft/
CC			=	gcc
LIBS	=	libft/libft.a  minilibx/libmlx.dylib

%.o: %.c cub3d.h
	cd $(@D) && $(CC) $(FLAGS) -c $(<F)

%.a %.dylib: FORCE
	$(MAKE) -C $(@D)

all: $(NAME)

$(NAME): $(LIBS) $(OBJS) $(NOBONUS:.c=.o)
	$(CC) -o $(NAME) $^
	install_name_tool -change libmlx.dylib minilibx/libmlx.dylib $(NAME)

bonus: $(LIBS) $(OBJS) $(BONUS:.c=.o)
	$(CC) -o $(NAME) $^
	install_name_tool -change libmlx.dylib minilibx/libmlx.dylib $(NAME)

FORCE:

clean:
	rm -f $(OBJS) $(BONUS:.c=.o) $(NOBONUS:.c=.o)
	$(LIBFTMAKE) clean
	$(MAKE) -C minilibx/ clean

fclean:
	rm -f $(NAME) $(OBJS) $(BONUS:.c=.o) $(NOBONUS:.c=.o)
	$(LIBFTMAKE) fclean
	$(MAKE) -C minilibx/ clean

re: fclean all

.PHONY:	all clean fclean re
