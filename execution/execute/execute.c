/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/12 04:40:58 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_com*    find_last(t_com *l_com)
{
    while (l_com->next)
        l_com = l_com->next;
    return l_com;
}

// int    size_t_node(t_command *stack)
// {
//     int i;

//     i = 0;
//     while (stack)
//     {
//         i++;
//         stack = stack->next;
//     }
//     return i;
// }

// void    merge_command(t_box *box)
// {
//     (void)box;
//     // while(box->l_com->next != NULL)
//     // {
//     //     printf("this dick: %s    type it is: %d \n", box->l_com->com ,box->l_com->type);
//     //     box->l_com = box->l_com->next;
//     // }
//     if(box->l_com->next->type)
//     {
//         if(box->l_com->next->type == 1)
//             pipe_two(box, box->l_com->com, box->l_com->next->next->com);
//     //     else if (box->l_com->next->type == 3)
//             // greater_than_sign();
//         // else
//             // printf("ANOTHER TYPE\n");
//     }
// }

void    l_com_command(t_box *box)
{
    (void)box;
    // if(box->l_com->next->type == 3)
    //     greater_than_sign(box);
    // if(box->l_com->next->type == 2)
    // t_com *lst = find_last(box->l_com);
    while (box->l_com)
    {
        if(box->l_com->type == 2)
        {
            check_if_it_is(box, box->l_com->next->com);
            if(box->check_val)
            {
                break;
            }
            // printf("%d\n", box->check_val);
            // if(box->check_val)
                // printf("%s\n", "sir 3alah");
            // else
            // break;
                
        }
        //     less_than_sign(box, lst);
        // printf("%s\n", box->l_com->com);
        box->l_com = box->l_com->next;
    }

    if(!box->check_val)
        execute_c_options(box);
    // if(!box->check_val)
    // {
    //     printf("KAWYA DA3WA\n");
    // }
    // printf("la fin: %s\n", box->l_com->com);
    // printf("lst: %s\n", lst->com);
}

void    execute(t_box *box)
{
    // printf("size_t_node: %d\n", size_t_node(box->node->command));
    // get_options(box->node->command);
    // if(size_t_node((box->node->command)) > 1)
        // merge_command(box);
    // else
    if(length_stack(box->l_com) > 1)
        l_com_command(box);
        // printf("+++++++++++\n");
    // int i = 0;
    // while (box->node->command->options[i])
    // {
        // printf("%s\n", box->node->command->options[i]);
        // i++;
    // }
}

// ila kan chi file makaynch i7bes