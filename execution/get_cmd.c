/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:33:42 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/15 14:59:27 by msbai            ###   ########.fr       */
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
        rebuild_exit();  
    else if((ft_strncmp(box->l_com->com, "export", ft_strlen("export")) == 0))
        rebuild_export(box);
    else if((ft_strncmp(box->l_com->com, "pwd", ft_strlen("pwd")) == 0))
            rebuild_pwd(length_stack(box->l_com), box->l_com);
    else if((ft_strncmp(box->l_com->com, "unset", ft_strlen("unset")) == 0))
        rebuild_unset();  
}



int    get_cmd(t_box *box)
{
    
    t_com *ls;
    // t_command    * node;
  

    // // node= NULL;
    
    ls =NULL;   
    
    if(!box->cmd)
    {
        printf("exit\n");
        box->exit_val = 0;
        return (1);
    }
    if (parsing(box))
        return 0;
    fill_finale(box);
    box->exit_val = 0;
    ls =box->l_com;
    // node = box->node->command;

    // set_builtins(box);    


    while(ls)
    {
        printf("%s => %d\n",ls->com, ls->type);
        ls = ls->next;
    }

    
    
    // printf("%p\n", node);
    // if (node)
    //     printf("m3art ach tra hnya node \n");
    //  printf("%s => %d\n",ls->com, ls->type);
    // while(ls)
    // {
    //     printf("%s => %d\n",ls->com, ls->type);
        
    //     ls = ls->next;
    // }
    // node = box->node->command;
    // int i = 0;
    // while (node)
    // {
    //     printf("\n options\n");
    //     while (node->options && node->options[i])
    //     {
    //         printf("%s ", node->options[i++]);
    //     }
    //     printf("\n redirection\n");
    //     while (node->redirection)
    //     {
    //         printf("%s ", node->redirection->str);
    //         node->redirection = node->redirection->next;
    //     }
    //     i = 0;
    //     node = node->next;
    // }
    // printf("\n");

    // t_tmp_ls = ls;
    // if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
    //     echo(t_tmp_ls, ls->next->com);

    // set_commands(box->l_com, box); 
    // printf("--%s--", prompt() 
    free_node(box->node);
    return (0);
}
