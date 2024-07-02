/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:36:10 by msbai             #+#    #+#             */
/*   Updated: 2024/06/30 12:56:35 by msbai            ###   ########.fr       */
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

typedef struct s_box
{
    char  *cmd;
    t_com *l_com;
    char **ptr;
    env * env;
} t_box;
void    get_cmd(t_box *box);

//----------------msbai----------------//
char    *prompt();
env     *fill_env(char **env);
void    parsing(t_box *box);
void    free_all(t_box *box);
void    free_env(env *env);
void    fill_list(char **ptr, t_box *box);
void    replace_var(t_box *box);
void    join(char **dest, char * src, int i);
char    *str_replace(char * s1, char *rep, char *with);
void    free_env(env *lst);
void    collect_string(t_box *box);
void    simple_check(char *com);
t_com   *new_node(char *str);
void    split_pip(t_box *box);
void    exit_f(char *s, char *msg);
void    remove_qoute(t_box *box);
void    check_gramer(t_box * box);
void    delete_emty(t_box *box);
void    put_type(t_box *box);
//----------------zibnoukh----------------//

/*builtins*/
void    echo(t_com *t_tmp_ls, char *next);
void    rebuild_env(env *all_env);
void    rebuild_exit();
void    rebuild_cd();

/*functions*/
int    length_stack(t_com *stack);

#endif
