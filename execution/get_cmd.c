/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/26 10:57:16 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    get_cmd_to_builtins(t_box *box)
{
    int pid;
    t_com *ls;
    t_com *t_tmp_ls;
    
    pid = fork();
    if (!pid)
    {
        parsing(box);
        ls = box->l_com;
        t_tmp_ls = ls;
        if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
            echo(t_tmp_ls, ls->next->com);
        exit(0);
    }
    else
        wait(NULL);    
}

void    get_cmd(t_box *box)
{
    get_cmd_to_builtins(box);
}
