/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:08:35 by msbai             #+#    #+#             */
/*   Updated: 2024/05/22 09:11:05 by msbai            ###   ########.fr       */
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
//-------color-------//
# define DCOLORB "\033[49m"
# define DCOLORF "\033[39m"
# define GREENB  "\033[42m"
# define GREENF  "\033[32m"

typedef struct s_prompt
{
    char * color;
    char * name ;
    char * host;
    char  path[300];
} t_primpt;
typedef struct s_box
{
    char  *cmd;
} t_box;
void    get_cmd(t_box *box);

//----------------msbai----------------//
char * prompt();

#endif