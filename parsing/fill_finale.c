/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_finale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:56:03 by msbai             #+#    #+#             */
/*   Updated: 2024/07/12 05:22:18 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


// void add_com(t_com *ls,  t_node * mode_)
// {
    
// }
void take_it(t_redirection   **re, t_com *ls)
{
    t_redirection   *last_re;
    t_redirection   *new_re;
    last_re = *re;
    while (last_re && last_re->next)
    {
        last_re = last_re->next;
    }
    new_re = ft_calloc(1, sizeof(t_redirection));
    new_re->flag = ls->prev->type;
    new_re->str = ls->com; 
    new_re->next = NULL;
    if(last_re)
        last_re->next = new_re;
    else
        *re = new_re;
}
// void take_it(t_redirection **re, t_com *ls)
// {
//     t_redirection *current = *re;
//     t_redirection *new_redirection;

//     while (current && current->next)
//     {
//         current = current->next;
//     }

//     new_redirection = ft_calloc(1, sizeof(t_redirection));
//     new_redirection->flag = ls->prev->type;
//     new_redirection->str = strdup(ls->com); // Duplicate string to avoid dangling pointers
//     new_redirection->next = NULL;

//     if (current)
//     {
//         current->next = new_redirection;
//     }
//     else
//     {
//         *re = new_redirection;
//     }
// }
void fill_finale(t_box *box)
{
    t_com *ls;
    t_node * node_; 
    t_command * command;
    
    node_ = ft_calloc(1, sizeof(t_node));
    node_->command = ft_calloc(1, sizeof(t_command));
    box->node = node_;
    ls = box->l_com;
    command = node_->command;
    command->next = NULL;
    while (ls)
    {
        if (!ls->type)
            command->options = join2pointer(command->options, ls->com);
        else if (ls->type > 1)
        {
            ls =  ls->next;
            take_it(&command->redirection, ls);
        }
        else if (ls->type == 1)
        {
            command->next = ft_calloc(1, sizeof(t_command));
            command = command->next; 
            command->next = NULL;
        }
        ls =  ls->next;
    }
}



// void fill_finale(t_box *box)
// {
//     t_com *ls;
//     t_command *current_command;
//     t_node *node_;

//     node_ = ft_calloc(1, sizeof(t_node));
//     current_command = ft_calloc(1, sizeof(t_command));
//     node_->command = current_command;
//     box->node = node_;
//     ls = box->l_com;

//     while (ls)
//     {
//         if (ls->type == 0)
//         {
//             // Add command option
//             current_command->options = join2pointer(current_command->options, ls->com);
//         }
//         else if (ls->type > 1)
//         {
//             ls = ls->next; // Move to the next item for redirection string
//             take_it(&(current_command->redirection), ls);
//         }
//         else if (ls->type == 1)
//         {
//             // Create a new command and move to it
//             current_command->next = ft_calloc(1, sizeof(t_command));
//             current_command = current_command->next;
//         }
//         ls = ls->next;
//     }
// }
