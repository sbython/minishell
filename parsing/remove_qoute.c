/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_qoute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:38:13 by msbai             #+#    #+#             */
/*   Updated: 2024/07/09 06:16:14 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void remove_(char *str)
{
    char c;
    int   i;

    i = 0;
    while(str[i])
    {
        c = str[i];
        if (c == '"' || c == '\'')
        {
            ft_memmove(&str[i],&str[i + 1], ft_strlen(&str[i + 1]));
            str[ft_strlen(str) -1] = 0; 
            while(str[i] && str[i] != c)
                i++;
            if (str[i] == c)
                ft_memmove(&str[i],&str[i + 1], ft_strlen(&str[i + 1]));
            str[ft_strlen(str) -1] = 0; 
        }
        else
            i++;
    }
}

void    remove_qoute(t_box *box)
{
    t_com *ls;
    char *tmp;
    ls = box->l_com;
    while(ls)
    {
        tmp = ft_strtrim(ls->com, "\t");
        free(ls->com);
        ls->com = tmp;   
        if (ft_strchr(ls->com , '\'')  || ft_strchr(ls->com , '"'))
                remove_(ls->com);
        ls = ls->next;
    }
}