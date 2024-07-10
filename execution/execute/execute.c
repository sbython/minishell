/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/09 23:54:26 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    size_t_node(t_command *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

void    merge_command(t_box *box)
{
    // while(box->l_com->next != NULL)
    // {
    //     printf("this dick: %s    type it is: %d \n", box->l_com->com ,box->l_com->type);
    //     box->l_com = box->l_com->next;
    // }
    if(box->l_com->next->type)
    {
        if(box->l_com->next->type == 1)
        {
            pipe_two(box->l_com->com, box->l_com->next->next->com);
        }
        else
            printf("ANOTHER TYPE\n");
    }
}

void    execute(t_box *box)
{
    // printf("size_t_node: %d\n", size_t_node(box->node->command));
    // get_options(box->node->command);
    if(size_t_node((box->node->command)) > 1)
        merge_command(box);
    else
        printf("ONE COMMAND\n");
}
