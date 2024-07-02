/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:08:35 by msbai             #+#    #+#             */
/*   Updated: 2024/07/02 13:22:17 by zibnoukh         ###   ########.fr       */
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

typedef struct s_listcom
{
    char *com;
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


//----------------zibnoukh----------------//

/*builtins*/
void    rebuild_cd();
void    rebuild_echo(t_com *t_tmp_ls, char *next);
void    rebuild_env(env *all_env);
void    rebuild_exit();
// void    rebuild_export(t_com *ls, env *all_env, char *next);
void    rebuild_export(t_box *box);
void    rebuild_pwd(int size, t_com *ls);
void    rebuild_unset();

/*functions*/
int    length_stack(t_com *stack);
#endif
