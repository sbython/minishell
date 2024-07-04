/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:23 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 01:50:33 by msbai            ###   ########.fr       */
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
    char *str;
    char **ptr;
    
    str = ft_strtrim(box->cmd, " \t");
    free(box->cmd);
    box->cmd = str;
    simple_check(box->cmd);
    if (ft_strnstr(box->cmd, "||" , -1))
        exit_f(box->cmd, "minishell: syntax error near unexpected token `|'\n");
    ptr = ft_split(box->cmd , ' ');
    fill_list(ptr, box);
    free_2ptr(ptr);
    collect_string(box);
    replace_var(box);
    split_pip(box);
    put_type(box);
    delete_emty(box);
    check_gramer(box);
    remove_qoute(box);

    // t_com *ls;
    // ls = box->l_com;

    // while(ls)
    // {
    //     printf("%s => %d\n",ls->com, ls->type);
        
    //     ls = ls->next;
    // }
        fill_finale(box);
}
