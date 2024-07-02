/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/29 23:21:08 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    set_commands(t_com *ls, t_box *box)
{
    if(ft_strncmp(ls->com, "cd", ft_strlen(ls->com)) == 0)
        rebuild_cd();
    else if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
    {
        if(length_stack(ls) == 1)
            ft_putstr_fd("\n", 1);
        echo(ls, ls->next->com);
    }
    else if((ft_strncmp(ls->com, "env", ft_strlen(ls->com)) == 0))
        rebuild_env(box->env);  
    else if((ft_strncmp(ls->com, "exit", ft_strlen(ls->com)) == 0))
        rebuild_exit(box->env);  
}

void    get_cmd_to_builtins(t_box *box)
{
    int pid;
    t_com *ls;

    
    ls = NULL;
    pid = fork();
    if (!pid)
    {
        parsing(box);
        ls = box->l_com;

        while(ls)
        {
            printf("%s => %d\n",ls->com, ls->type);
            ls = ls->next;
        }
        // t_tmp_ls = ls;
        // if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
        //     echo(t_tmp_ls, ls->next->com);

        // set_commands(box->l_com, box);    

        exit(0);
    }
    else
        wait(NULL);    
}

void    get_cmd(t_box *box)
{
    get_cmd_to_builtins(box);
}

