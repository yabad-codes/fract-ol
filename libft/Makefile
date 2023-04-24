SRCS	=	ft_isalpha.c ft_atoi.c ft_isdigit.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_strncmp.c ft_strlcpy.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_split.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar rc

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} $?
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re