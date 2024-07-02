/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/02 12:43:33 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    set_builtins(t_box *box)
{
    if(ft_strncmp(box->l_com->com, "cd", ft_strlen(box->l_com->com)) == 0)
        rebuild_cd();
    else if(ft_strncmp(box->l_com->com, "echo", ft_strlen(box->l_com->com)) == 0)
    {
        if(length_stack(box->l_com) == 1)
            ft_putstr_fd("\n", 1);
        rebuild_echo(box->l_com, box->l_com->next->com);
    }
    else if((ft_strncmp(box->l_com->com, "env", ft_strlen(box->l_com->com)) == 0))
        rebuild_env(box->env);  
    else if((ft_strncmp(box->l_com->com, "exit", ft_strlen(box->l_com->com)) == 0))
        rebuild_exit(box->env);  
    else if((ft_strncmp(box->l_com->com, "export", ft_strlen(box->l_com->com)) == 0))
        rebuild_export(box);  
    else if((ft_strncmp(box->l_com->com, "pwd", ft_strlen(box->l_com->com)) == 0))
            rebuild_pwd(length_stack(box->l_com), box->l_com);
    else if((ft_strncmp(box->l_com->com, "unset", ft_strlen(box->l_com->com)) == 0))
        rebuild_unset(box->env);  
}

void    get_cmd_(t_box *box)
{
    int pid;
    t_com *ls;
    
    ls = NULL;
    pid = fork();
    if (!pid)
    {
        parsing(box);
        ls = box->l_com;
        set_builtins(box);    
        exit(0);
    }
    else
        wait(NULL);    
}

void    get_cmd(t_box *box)
{
    get_cmd_(box);
}
