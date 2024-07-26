/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:34:21 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/25 20:13:18 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//-------library-------//
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
//-------colors-------//
# define DCOLORB "\033[49m"
# define DCOLORF "\033[39m"
# define GREENB "\033[42m"
# define GREENF "\033[32m"

typedef struct s_env
{
	char					*name;
	char					*vale;
	int						position;
	struct s_env			*next;
	struct s_env			*prev;
}							t_env;

/*
    type 
    0 string
    1  |
    2 <
    3 >         
    4 << 
    5 >>
*/

typedef struct s_listcom
{
	char					*com;
	int						type;
	struct s_listcom		*next;
	struct s_listcom		*prev;
}							t_com;

typedef struct s_redirection
{
	char					*str;
	int						flag;
	int						output_test_file;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_command
{
	t_redirection			*redirection;
	char					**options;
	struct s_command		*next;

    int append;
}							t_command;

typedef struct s_node
{
	t_command				*command;
	pid_t					last;

}							t_node;

typedef struct s_box
{
	char					*cmd;
	t_com					*l_com;
	char					**ptr;
	t_node					*node;
	t_env					*env;
	int						max_here_doc_val;
	int						exit_val;
	char					**full_env;
	int						done_heardoc;
	int						MAX_COMMANDS;
	char 					*input_file;
    char 					*output_file;
	char					*speinput_file;
	int						valid_her;
	int						valid_flag;
	int						append;
	int						error_file;
	char*					export_val;
	char*					export_name;
}							t_box;

//----------------msbai----------------//

char						*prompt(void);
t_env						*fill_env(char **env);
int							parsing(t_box *box);
void						free_all(t_box *box);
void						free_env(t_env *env);
void						fill_list(char **ptr, t_box *box);
void						replace_var(t_box *box);
void						join(char **dest, char *src, int i);
char						*str_replace(char *s1, char *rep, char *with);
int							collect_string(t_box *box);
int							simple_check(t_box *box);
t_com						*new_node(char *str);
void						split_pip(t_box *box);
void						exit_f(char *s, char *msg, t_box *box);
void						remove_qoute(t_box *box);
int							check_gramer(t_box *box);
void						delete_emty(t_box *box);
void						put_type(t_box *box);
char						**join2pointer(char **com, char *str);
void						fill_finale(t_box *box);
void						free_node(t_node *node);
int							is_token(char *ls, int i);
void						tap_to_space(char *s);
char						*ft_dchr(const char *s, int c);
int							ft_isdelimiter(char *str);
char						*replace(t_com *str, t_box *box);
int							slen(char *str);
char						**ft_newsplit(char *s);
void						free_2ptr(char **p);
t_com						*last_node(t_com *node);
void						sp(t_com **list, char *str, t_com *last,
								t_com **n_box);
char						*new_strnstr(char *str, char *str1);
void						handlesignal(int i, t_box *box);
char						*ft_dstr(const char *s, char * c);
void						remove_(char *str);
char						*get_to(char *str, char c);
char						*get_val(char *str, t_env *en, t_box *box);
int							len_to(char *str, char c);
char						*new_replace(char *str, t_box *box);

//----------------zibnoukh----------------//

void    execute(t_box *box);
void    get_command(t_command *command);
char**    get_path__(t_env *all_env);
char *fully(char **r, char *cmd);
int    check_heardoc(t_redirection *redirection);
char*   random_file(char *file);
void    open_all_files(t_redirection *red);
void    run_headoc__(t_box *box);
int    ft_redirection(t_box*box, t_redirection *redirection);
void    more_then___(t_box *box);
int    builtins(char **ptr,t_box * box);
char* filter_v(char *r);
char* filter_n(char *r);
t_env*	sort_env(t_env *env);

/*builtins*/

int    rebuild_cd(char **ptr, t_env *env__);
int    rebuild_echo(char **ptr);
int    rebuild_pwd(char **ptr);
int    rebuild_env(char **ptr, t_env *env__);
int    rebuild_exit(char **ptr, t_box *box);
int    rebuild_export(char **ptr, t_env *env);
int    rebuild_unset(char **ptr, t_box *box);

/*functions*/

int    length_stack(t_com *stack);
int    get_cmd(t_box *box);

#endif
