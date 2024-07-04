/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_emty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:13:28 by msbai             #+#    #+#             */
/*   Updated: 2024/06/30 10:59:12 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void delete_(t_com *ls)
{
    t_com *next;
    t_com *prev;
    
    next = ls->next;
    prev = ls->prev;

    if(next)
        next->prev = prev;
    prev->next = next;
    free(ls->com);
    free(ls);
}

void delete_emty(t_box *box)
{
    t_com *ls;
    t_com *tmp;
    char  *str;
    ls = box->l_com;
    while (ls)
    {
        str = ls->com;
        if(!*str)
        {
            tmp = ls->next;
            delete_(ls);
            ls = tmp;
        }
        else
             ls = ls->next;
    }
    
}