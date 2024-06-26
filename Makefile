CC= cc
CFLAGS = -Wall -Werror -Wextra  -g 
RM = rm -rf
NAME = minishell
LIBFT = libft/libft.a
SRC_E= execution/get_cmd.c execution/builtins/cd/cd.c execution/builtins/pwd/pwd.c \
	   execution/builtins/echo/echo.c execution/builtins/env/env.c \
	   execution/builtins/exit/exit.c execution/builtins/functions/length_stack.c \
	   execution/builtins/export/export.c execution/builtins/unset/unset.c \

SRC_P= parsing/minishell.c \
		parsing/prompt.c \
		parsing/parsing.c \
		parsing/fill_env.c \
		parsing/free_all.c \
		parsing/fill_list_com.c \
		parsing/replace_var.c \
		parsing/replace.c\
		parsing/collect_string.c\
		parsing/simple_check.c\
		parsing/split_pip.c \

OBJ= ${SRC_P:.c=.o} ${SRC_E:.c=.o}


all : ${NAME} 

${NAME}: ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJ}  -lreadline ${LIBFT} -o $@
	

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
${LIBFT}:
	@${MAKE} -C ./libft
	@${MAKE} bonus -C ./libft
clean:
	@${RM} ${OBJ}
	@${MAKE} -C ./libft clean

fclean:
	@${RM} ${OBJ} ${NAME}
	@${MAKE} -C ./libft fclean

re: fclean all