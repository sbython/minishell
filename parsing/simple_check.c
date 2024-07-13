/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:11:54 by msbai             #+#    #+#             */
/*   Updated: 2024/07/09 22:35:59 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void exit_f(char *s, char *msg, t_box * box)
{
    // int pid;
    (void) s;
    // (void) box;
    ft_putstr_fd(msg, 2);
    // pid = fork();
    // if (!pid)
    //  {
    //    // free(box->cmd);
    //     exit(2);
    // }
    // else 
    // {
    //     waitpid(pid, &box->node->exit_nb, 0);
    // }
    box->exit_val =  2;
}
int check_(char *s)
{
    char c;
    int   i;

    i = 0;
    while(s[i])
    {
        c = s[i];
        if (c == '"' || c == '\'')
        {
            i++;
            while(s[i] && s[i] != c)
                i++;
            if (s[i] == c)
                i++;
        }
        else if (!ft_strncmp(s + i , "<<<", 3) || !ft_strncmp(s + i , ">>>", 3))
            return (0);
        else
            i++;
    }
    return (1);     
}
int simple_check(t_box *box)
{
    char *com;

    com = box->cmd;
    if(!*com)
        return 1;
    if (com[0] == '|' || com[ft_strlen(com) - 1] == '|')
    {
        exit_f(com ,"minishell: syntax error near unexpected token `|'\n",box);
        return (1);
    }
    else if (!(ft_strncmp(com , "<<", -1) 
    && ft_strncmp(com , ">", -1) 
    && ft_strncmp(com , "<", -1) 
    && ft_strncmp(com , ">>", -1)
    // && ft_strncmp(com , ">>>", 3)
    && com))
    {
        ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
        exit_f(com , "`<< or >> or < or >'\n", box);
        return (1);
    }
    return (0);
}
