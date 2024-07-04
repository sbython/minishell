/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 19:53:44 by msbai            ###   ########.fr       */
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
    // t_com *ls;
    // t_command    * node;
  

    // node= NULL;
    
    // ls =NULL;   
    // node = box->node->command;
    pid = fork();
    if (!pid)
    {
        parsing(box);
        // ls =box->l_com;

        
        // if (!ls)
        //     printf("m3art ach tra hnya \n");
        // // printf("%p\n", node);
        // // if (node)
        // //     printf("m3art ach tra hnya node \n");
        // //  printf("%s => %d\n",ls->com, ls->type);
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
        //     while (node->options[i])
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
        
        // t_tmp_ls = ls;
        // if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
        //     echo(t_tmp_ls, ls->next->com);

        // set_commands(box->l_com, box);    
        free_node(box->node);
        exit(0);
    }
    else
        wait(NULL);    
}


// void get_cmd_to_builtins(t_box *box)
// {
//     int pid;
//     t_com *ls;
//     t_command *node;

//     ls = NULL;
//     node = NULL;

//     pid = fork();
//     if (pid == 0)
//     {
//         parsing(box);
//         ls = box->l_com;
//         node = box->node ? box->node->command : NULL;

//         if (!ls)
//         {
//             printf("l_com is empty\n");
//         }
//         else
//         {
//             printf("l_com is not empty\n");
//             while (ls)
//             {
//                 printf("%s => %d\n", ls->com, ls->type);
//                 ls = ls->next;
//             }
//         }

//         if (node)
//         {
//             int i;
//             printf("Node options and redirections:\n");
//             while (node)
//             {
//                 printf("Options:\n");
//                 if (node->options)
//                 {
//                     i = 0;
//                     while (node->options[i])
//                     {
//                         printf("%s ", node->options[i++]);
//                     }
//                     printf("\n");
//                 }
//                 printf("Redirections:\n");
//                 t_redirection *redir = node->redirection;
//                 while (redir)
//                 {
//                     printf("%s ", redir->str);
//                     redir = redir->next;
//                 }
//                 printf("\n");

//                 node = node->next;
//             }
//         }
//         else
//         {
//             printf("Node is NULL\n");
//         }

//         exit(0);
//     }
//     else
//     {
//         wait(NULL);
//     }
// }
void    get_cmd(t_box *box)
{
    get_cmd_to_builtins(box);
}

