/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gramer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:57:19 by msbai             #+#    #+#             */
/*   Updated: 2024/07/06 03:21:39 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int is_token(char * ls, int i)
{
    return(!ls || ( (!ft_strncmp(ls, "|", -1) && i)
        || !ft_strncmp(ls, "<<",-1)
        || !ft_strncmp(ls, ">>", -1)
        || !ft_strncmp(ls, "<", -1)
        || !ft_strncmp(ls, ">", -1)));
}
int  check_gramer(t_box * box)
{
    t_com *ls;

    ls = box->l_com;
    while (ls)
    {
        if ((ls->next &&  ls->type > 1 && ls->next->type >= 1) 
            || (!ls->next && ls->type >= 1 ))
        {
            ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
            exit_f(NULL , "`<< or >> or < or >'\n",box); 
            return (1);
        }
        else if(ls->next &&  ls->type == 1 && ls->next->type == 1)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
            exit_f(NULL , "`<< or >> or < or >'\n",box); 
            return (1);
        }
        ls = ls->next;
    }
    return (0);
}