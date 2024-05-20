CC= cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf

SRC_E= execution/get_cmd.c \

SRC_P= parsing/minishell.c \

OBJ= ${SRC_P:.c=.o} ${SRC_E:.c=.o}

MINISHELL = minishell

${MINISHELL}: ${OBJ}
	${CC} ${CFLAGS} -lreadline -o $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean:
	${RM} ${OBJ} ${MINISHELL}

re: fclean ${MINISHELL}