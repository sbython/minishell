/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/10 21:08:18 by zibnoukh         ###   ########.fr       */
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
    (void)box;
    // while(box->l_com->next != NULL)
    // {
    //     printf("this dick: %s    type it is: %d \n", box->l_com->com ,box->l_com->type);
    //     box->l_com = box->l_com->next;
    // }
    if(box->l_com->next->type)
    {
        if(box->l_com->next->type == 1)
            pipe_two(box, box->l_com->com, box->l_com->next->next->com);
    //     else if (box->l_com->next->type == 3)
            // greater_than_sign();
        // else
            // printf("ANOTHER TYPE\n");
    }
}

void    l_com_command(t_box *box)
{
    if(box->l_com->next->type == 3)
        greater_than_sign(box);
    else if(box->l_com->next->type == 2)
        less_than_sign();
}

void    execute(t_box *box)
{
    // printf("size_t_node: %d\n", size_t_node(box->node->command));
    // get_options(box->node->command);
    if(size_t_node((box->node->command)) > 1)
        merge_command(box);
    // else
    // l_com_command(box);
}
