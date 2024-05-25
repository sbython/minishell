CC= cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf
NAME = minishell
LIBFT = libft/libft.a
SRC_E= execution/get_cmd.c \

SRC_P= parsing/minishell.c \
		parsing/prompt.c

OBJ= ${SRC_P:.c=.o} ${SRC_E:.c=.o}


all : ${NAME} 

${NAME}: ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} -lreadline ${OBJ}  ${LIBFT} -o $@
	

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
${LIBFT}:
	@${MAKE} -C ./libft
clean:
	@${RM} ${OBJ}
	@${MAKE} -C ./libft clean

fclean:
	@${RM} ${OBJ} ${NAME}
	@${MAKE} -C ./libft fclean

re: fclean all