/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:12:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/09 23:17:55 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void    set_builtins(t_box *box)
{
    if(ft_strncmp(box->l_com->com, "cd", ft_strlen(box->l_com->com)) == 0)
        rebuild_cd(box);
    else if(ft_strncmp(box->l_com->com, "echo", ft_strlen("echo")) == 0)
    {
        if(length_stack(box->l_com) == 1)
            ft_putstr_fd("\n", 1);
        rebuild_echo(box->l_com, box->l_com->next->com);
    }
    else if((ft_strncmp(box->l_com->com, "env", ft_strlen("env")) == 0))
        rebuild_env(box->env);  
    else if((ft_strncmp(box->l_com->com, "exit", ft_strlen("exit")) == 0))
        rebuild_exit(box->env);  
    else if((ft_strncmp(box->l_com->com, "export", ft_strlen("export")) == 0))
        rebuild_export(box);
    else if((ft_strncmp(box->l_com->com, "pwd", ft_strlen("pwd")) == 0))
            rebuild_pwd(length_stack(box->l_com), box->l_com);
    else if((ft_strncmp(box->l_com->com, "unset", ft_strlen("unset")) == 0))
        rebuild_unset(box->env);
}

// int    get_cmd_(t_box *box)
// {
//     if(!box->cmd)
//     {
//         parsing(box);
//         free_node(box->node);
//         exit(0);
//     }
//     if (parsing(box))
//         return 0;
//     free_node(box->node);
//     return (0);
// }

void    test(t_box *box)
{
    printf("type: %d\n", box->l_com->next->type);
}

int    get_cmd(t_box *box)
{
    (void)box;

    if(!box->cmd)
    {
        printf("exit\n");
        box->exit_val = 0;
        return (1);
    }
    if (parsing(box))
        return 0;

    // set_builtins(box);
    // test(box);
    execute(box);
    // printf("FFFF");

    return (0);
}
