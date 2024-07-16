CC= cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf
NAME = minishell
LIBFT = libft/libft.a
SRC_E= execution/get_cmd.c execution/builtins/cd/cd.c execution/builtins/pwd/pwd.c \
	   execution/builtins/echo/echo.c execution/builtins/env/env.c \
	   execution/builtins/exit/exit.c execution/builtins/functions/length_stack.c \
	   execution/builtins/export/export.c execution/builtins/unset/unset.c \
	   execution/execute/execute.c execution/execute/get_command.c \
	   execution/execute/get_options.c execution/execute/get_redirection.c \
	   execution/execute/pipe_two.c execution/execute/greater_than_sign.c \
	   execution/execute/less_than_sign.c execution/execute/execute_c_options.c \
	   execution/execute/check_if_it_is.c execution/execute/execute_heardoc.c \
	   execution/execute/left_shift.c execution/execute/right_shift.c \
	   execution/execute/get_path.c execution/execute/redirection.c \

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
		parsing/remove_qoute.c \
		parsing/check_gramer.c \
		parsing/delete_emty.c \
		parsing/put_type.c \
		parsing/fill_finale.c \
		parsing/join2pointer.c \
		parsing/new_split.c\
		parsing/sp.c \
		parsing/here_doc.c

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