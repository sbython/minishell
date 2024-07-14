/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/13 22:00:45 by zibnoukh         ###   ########.fr       */
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

// void    l_com_command(t_box *box)
// {
//     // int exe;

//     // exe = 1;
//     while (box->l_com)
//     {
//         if(box->l_com->type == 2)
//         {
//             check_if_it_is(box, box->l_com->next->com);
//             if(box->check_val)
//                 break;
                
//         }
//         // else if (box->l_com->type == 4)
//         // {
//         //     printf("<<\n");
//         //     break;
//         // }
//         box->l_com = box->l_com->next;
//     }

//     // if(!box->check_val)
//     //     execute_c_options(box);
// }

int    no_fake_file(t_com *l_com)
{
    int check;
    while (l_com)
    {
        if(ft_strncmp(l_com->com, "<", 1) == 0)
        {
            check = check_if_it_is(l_com->next->com);
            if(check)
            {
                return 0;
                break;
            }
        }
        l_com = l_com->next;
    }
    return 1;
}

void    execute(t_box *box)
{
    if(length_stack(box->l_com) > 1)
    {
        // if(no_fake_file(box->l_com))
        // {
        //     type_of_exe(box, box->l_com);   
        // }
        while (box->node->command->redirection)
        {
            printf("str: %s\n", box->node->command->redirection->str);
            printf("flag: %d\n", box->node->command->redirection->flag);
            // if(box->node->command->redirection->next->next->str)
                // printf("next: %s\n", box->node->command->redirection->next->str);
            box->node->command->redirection = box->node->command->redirection->next;
        }

        // box->node->command->next->options
        
        // int i = 0;
        // while (box->node->command->options[i])
        // {
        //     // box->node->command->options
        //     printf("%s\n", box->node->command->options[i]);
        //     i++;
        // }
        
        // printf("%d\n", box->check_val);
        // if(box->check_val)
            // execute_c_options(box);
        // l_com_command(box);
    }
}

// 00 - no fake file
// stop until end real filedsa
