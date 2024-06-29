/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gramer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:57:19 by msbai             #+#    #+#             */
/*   Updated: 2024/06/28 21:17:03 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int is_token(t_com *ls)
{
    return(ls && ( !ft_strncmp(ls->com, "|", -1)
        || !ft_strncmp(ls->com, "<<",-1)
        || !ft_strncmp(ls->com, ">>", -1)
        || !ft_strncmp(ls->com, "<", -1)
        || !ft_strncmp(ls->com, ">", -1)));
}
void check_gramer(t_box * box)
{
    t_com *ls;

    ls = box->l_com;
    while (ls)
    {
        if (is_token(ls) && is_token(ls->next))
        {
            ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
            exit_f(NULL , "`<< or >> or < or >'\n"); 
        }
        
        ls = ls->next;
    }
    
}