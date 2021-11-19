SRCS	=	main.c geometry.c hook.c  util1.c util5.c g.c
HEADERS =   libfdf.h
OBJS	=	$(SRCS:.c=.o)
NAME	=	Cub3D
LIBFT   =   libft.a
LIBFT_DIR = libft
GNL     =   libgnl.a
GNL_DIR =   gnl
MINX    =   libmlx.a
MINX_DIR =  minilibx_macos

INCLUDES  = -L${LIBFT_DIR} -L${GNL_DIR} -L${MINX_DIR}
CC		=	gcc
AR     =   ar
RM      =   rm -f
CFLAGS	=	-Wall -Wextra -Werror -O0 -g
%.o:	%.c ${HEADERS}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:	${NAME}
${NAME}:	${LIBFT_DIR}${LIBFT} ${GNL_DIR}${GNL}  ${MINX_DIR}${MINX} ${OBJS}
			#cp ${LIBFT_DIR}${LIBFT} ${NAME}
			${CC} ${INCLUDES} -lft -lgnl -lmlx -framework OpenGL -framework  AppKit ${OBJS}  -o  ${NAME}
			install_name_tool -change libmlx.dylib minilibx_macos/libmlx.dylib Cub3D

${LIBFT_DIR}${LIBFT}:	${LIBFT_DIR}
					${MAKE} -C ${LIBFT_DIR}
${GNL_DIR}${GNL}:	${GNL_DIR}
					${MAKE} -C ${GNL_DIR}
${MINX_DIR}${MINX}:	${MINX_DIR}
					${MAKE} -C ${MINX_DIR}

clean:
			${RM} ${OBJS}
			${MAKE} -C ${LIBFT_DIR} clean
			${MAKE} -C ${GNL_DIR} clean
			${MAKE} -C ${MINX_DIR} clean

fclean:		clean
			${RM} ${NAME}
			${MAKE} -C ${LIBFT_DIR} fclean
			${MAKE} -C ${GNL_DIR} fclean


re:			fclean all

.PHONY:		all make_libft clean fclean re
