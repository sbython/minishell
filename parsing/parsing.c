/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:23 by msbai             #+#    #+#             */
/*   Updated: 2024/07/13 00:23:42 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"

void free_2ptr(char **p)
{
    int i;

    i = 0;
    while(p[i])
        free(p[i++]);
    free(p);
}

int  parsing(t_box *box)
{
    char *str;
    
    str = ft_strtrim(box->cmd, " \t");
    free(box->cmd);
    box->cmd = str;
    if (simple_check(box))  
        return (1);
    else if (ft_strnstr(box->cmd, "||" , -1))
    {
        exit_f(box->cmd, "minishell: syntax error near unexpected token `|'\n",box);
        return(1);
    }
    box->ptr = ft_newsplit(box->cmd);
    fill_list(box->ptr, box);
    free_2ptr(box->ptr);
    if (collect_string(box))
        return 1;
    split_pip(box);
    replace_var(box);
    put_type(box);
    if (check_gramer(box))
        return (1);
    
    delete_emty(box);
 

    remove_qoute(box);
    return 0;
}
    