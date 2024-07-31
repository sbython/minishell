CC= cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
NAME = minishell
LIBFT = libft/libft.a
SRC_E= execution/get_cmd.c execution/builtins/cd/cd.c execution/builtins/pwd/pwd.c \
	   execution/builtins/echo/echo.c execution/builtins/env/env.c \
	   execution/builtins/exit/exit.c execution/builtins/functions/length_stack.c \
	   execution/builtins/export/export.c execution/builtins/unset/unset.c \
	   execution/execute/the_access.c execution/execute/fully.c \
	   execution/execute/execute.c execution/execute/get_path__.c \
	   execution/execute/check_heardoc.c execution/execute/random_file.c \
	   execution/execute/run_all_heardocs.c execution/execute/more_then___utils.c \
	   execution/execute/ft_redirection.c execution/execute/more_then___.c \
	   execution/builtins/builtins.c execution/filter_n.c execution/filter_v.c \
	   execution/builtins/export/sort_env.c execution/builtins/export/add_env_variable.c \
	   execution/builtins/export/ft_utils.c execution/execute/how_her.c \
	   execution/execute/test.c \

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