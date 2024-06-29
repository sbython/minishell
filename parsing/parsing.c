/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:23 by msbai             #+#    #+#             */
/*   Updated: 2024/06/29 16:12:38 by msbai            ###   ########.fr       */
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

void  parsing(t_box *box)
{

    char **ptr;
    
    simple_check(box->cmd);
    if (ft_strnstr(box->cmd, "||" , -1))
        exit_f(box->cmd, "minishell: syntax error near unexpected token `|'\n");
    ptr = ft_split(box->cmd , ' ');
    fill_list(ptr, box);
    free_2ptr(ptr);
    collect_string(box);
    replace_var(box);
    split_pip(box);
    remove_qoute(box);
    delete_emty(box);
    check_gramer(box);
    // fill_finale(box)); :TODO.
}
