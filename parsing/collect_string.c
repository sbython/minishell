/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/07/06 02:45:32 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int check_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == '"')
        {
            str = ft_strchr(str + (i + 1), '"');
            if (!str)
                return (1);
            i = 0;
        }
        else if(str[i] == '\'')
        {
            str = ft_strchr(str + (i + 1), '\'');
            if (!str)
                return (1);
            i = 0;
        }
        i++;
        
    }
    return (0);
}

int join_node(t_box *box,  t_com *com)
{
    t_com *ne;
    t_com *ne_ne;


    if (!com->next)
    {
        printf("need a \" in the end of : %s\n" , com->com );
        exit_f(NULL,"",box);
        return (1);
    }
    ne = com->next;
    ne_ne = ne->next;

    join(&(com->com), " ", 0);
    join(&(com->com), ne->com, 1);
    com->next = ne_ne;
    if(ne_ne)
        ne_ne->prev = com;

    free(ne);
    return (0);
}
int collect_string(t_box *box)
{
    t_com *ls;
    ls = box->l_com;
    while (ls)
    {
        if (check_str(ls->com))
        {
            if(join_node(box, ls))
                return (1);            
        }
        else
            ls = ls->next;
        
    }
    return (0);
}
