/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:34:21 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/08 06:58:43 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//-------library-------//
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
#include <sys/wait.h>
//-------colors-------//
# define DCOLORB "\033[49m"
# define DCOLORF "\033[39m"
# define GREENB  "\033[42m"
# define GREENF  "\033[32m"



typedef struct s_env
{
    char *name;
    char *vale;
    int   position;
    struct s_env *next;
}env ;
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
    char *com;
    int type;
    struct s_listcom *next;
    struct s_listcom *prev;
}t_com;

typedef struct  s_redirection
{
    char                    *str;
    int                     flag;
    struct  s_redirection   *next;
} t_redirection;

typedef struct  s_command
{
    t_redirection   *redirection;
    char            **options;
     struct  s_command   *next;

} t_command;


typedef struct  s_node
{
    t_command    *command;
    pid_t        last;

} t_node;
typedef struct s_box
{
    char  *cmd;
    t_com *l_com;
    char **ptr;
    t_node * node;
    env * env;
    char *getpid;
    int exit_val;
} t_box;


//----------------msbai----------------//
char    *prompt();
env     *fill_env(char **env);
int    parsing(t_box *box);
void    free_all(t_box *box);
void    free_env(env *env);
void    fill_list(char **ptr, t_box *box);
void    replace_var(t_box *box);
void    join(char **dest, char * src, int i);
char    *str_replace(char * s1, char *rep, char *with);
void    free_env(env *lst);
int    collect_string(t_box *box);
int     simple_check(t_box *box);
t_com   *new_node(char *str);
void    split_pip(t_box *box);
void    exit_f(char *s, char *msg, t_box * box);
void    remove_qoute(t_box *box);
int     check_gramer(t_box * box);
void    delete_emty(t_box *box);
void    put_type(t_box *box);
char    **join2pointer(char **com, char *str);
void    fill_finale(t_box *box);
void    free_node(t_node *node);
int     is_token(char * ls, int i);
char    *get_pid();
void    tap_to_space(char *s);
//----------------zibnoukh----------------//

/*builtins*/
void    rebuild_cd(t_box *box);
void    rebuild_echo(t_com *t_tmp_ls, char *next);
void    rebuild_env(env *all_env);
void    rebuild_exit();
// void    rebuild_export(t_com *ls, env *all_env, char *next);
void    rebuild_export(t_box *box);
void    rebuild_pwd(int size, t_com *ls);
void    rebuild_unset();

/*functions*/
int    length_stack(t_com *stack);
int    get_cmd(t_box *box);
#endif
