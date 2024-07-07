/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:30 by msbai             #+#    #+#             */
/*   Updated: 2024/07/06 02:36:44 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void  free_env(env *lst)
{
    env *tmp;

    while (lst)
    {
        free(lst->name);
        // free(lst->vale);
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    free(lst);
}
void  free_lcom(t_com *lst)
{
    t_com *tmp;
    if(!lst)
        return ;
    while (lst)
    {
        free(lst->com);
        // free(lst->vale);
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }

}
void free_node(t_node *node)
{
    t_redirection   *tmp;   
    t_command   *tmp1;
    t_command    *com;
    if(!node)
        return ;
    com = node->command;
    while (com)
    {
        free(com->options);
        
        while (com->redirection)
        {
            tmp = com->redirection;
            
            com->redirection = com->redirection->next;
            free(tmp);
        }
        tmp1= com;
        com = com->next;
        free(tmp1);
    }
    free(node);
    node = NULL;
}
void  free_all(t_box *box)
{
    
    // if (box->cmd->com)
    //     printf("fwkergj");
    
    if(box && box->l_com)
    {
        free_lcom(box->l_com);
            box->l_com = NULL;
    }
    if(box && box->cmd)
    {
        free(box->cmd);
        box->cmd = NULL;
    }
}