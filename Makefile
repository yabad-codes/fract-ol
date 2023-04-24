SRCS = 	pars_check_args.c draw.c pars_str_double.c \
		exit.c init.c input.c main.c mandel_julia.c \
		p_converter.c zoom.c put_img.c

SRCS_BNS = 	z_pars_check_args_bonus.c z_draw_bonus.c pars_str_double.c \
			exit.c init.c z_input_bonus.c z_main_bonus.c mandel_julia.c \
			p_converter.c zoom.c put_img.c

OBJS = ${SRCS:.c=.o}

OBJS_BNS = ${SRCS_BNS:.c=.o}

NAME = fractol

NAME_BNS = fractol_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework AppKit -framework OpenGL -O3

RM = rm -f

${NAME}:	${OBJS}
			make -C libft all
			${CC} ${OBJS} libft/libft.a ${CFLAGS} ${MLX} -o $@

${NAME_BNS}:	${OBJS_BNS}
				make -C libft all
				${CC} ${OBJS_BNS} libft/libft.a ${CFLAGS} ${MLX} -o $@

all:	${NAME}

clean:
	make -C libft clean
	${RM} ${OBJS} ${OBJS_BNS}

fclean:	clean
	make -C libft fclean
	${RM} ${NAME} ${NAME_BNS}

re:	fclean all

bonus: ${NAME_BNS}

.PHONY: all bonus clean fclean re