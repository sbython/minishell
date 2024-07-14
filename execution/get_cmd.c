/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/07/13 00:52:59 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/13 21:34:43 by zibnoukh         ###   ########.fr       */
=======
/*   Created: 2024/07/04 20:33:42 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/14 08:05:36 by msbai            ###   ########.fr       */
>>>>>>> origin/test
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

<<<<<<< HEAD
// void get_cmd_to_builtins(t_box *box)

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
=======

>>>>>>> origin/test

int    get_cmd(t_box *box)
{
    (void)box;
    t_com *ls;
<<<<<<< HEAD
=======
    t_command    * node;
  
>>>>>>> origin/test

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
    ls =box->l_com;
    // node = box->node->command;

    // set_builtins(box);
    // test(box);
    execute(box);



<<<<<<< HEAD
=======
    
    
    // printf("%p\n", node);
    // if (node)
    //     printf("m3art ach tra hnya node \n");
    //  printf("%s => %d\n",ls->com, ls->type);
    // while(ls)
    // {
    //     printf("%s => %d\n",ls->com, ls->type);
        
    //     ls = ls->next;
    // }
    node = box->node->command;
    int i = 0;
    while (node)
    {
        printf("\n options\n");
        while (node->options && node->options[i])
        {
            printf("%s ", node->options[i++]);
        }
        printf("\n redirection\n");
        while (node->redirection)
        {
            printf("%s ", node->redirection->str);
            node->redirection = node->redirection->next;
        }
        i = 0;
        node = node->next;
    }
    printf("\n");

    // t_tmp_ls = ls;
    // if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
    //     echo(t_tmp_ls, ls->next->com);

    // set_commands(box->l_com, box); 
    // printf("--%s--", prompt() 
>>>>>>> origin/test
    free_node(box->node);

    return (0);
}
