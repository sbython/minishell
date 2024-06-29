/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:11:54 by msbai             #+#    #+#             */
/*   Updated: 2024/06/29 17:19:25 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void exit_f(char *s, char *msg)
{
    ft_putstr_fd(msg, 2);
    if(s)
        free(s);
    exit(1);
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
void simple_check(char *com)
{
    if(!*com)
        return;
    if (com[0] == '|' || com[ft_strlen(com) - 1] == '|')
         exit_f(com ,"minishell: syntax error near unexpected token `|'\n");
    else if (!(ft_strncmp(com , "<<", -1) 
    && ft_strncmp(com , ">", -1) 
    && ft_strncmp(com , "<", -1) 
    && ft_strncmp(com , ">>", -1)
    && check_(com)))
    {
        ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
        exit_f(com , "`<< or >> or < or >'\n");
    }
    
}