/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_heardoc___s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 09:10:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    max_here_document(int count)
{
    if(count >= 16)
    {
        printf("maximum here-document count exceeded");
        exit(0);
    }
}

int search_all(t_box* box)
{
    int max_here_document_val = 0;

    while (box->node->command)
    {
        while (box->node->command->redirection)
        {
            // if(box->node->command->redirection)
            // {
                box->node->command->redirection = box->node->command->redirection->next;
            // }
        }
        
        // int i = 0;
        // while (box->node->command->options[i])
        // {
        //     printf("%s\n", box->node->command->options[i]);
        //     i++;
        // }
        
        box->node->command = box->node->command->next;
    }

    return max_here_document_val;
}

void    run_all_heardoc___s(t_redirection *redirection)
{
    // (void)box;
    // int max_here_document_val = 0;
    // max_here_document_val = search_all(box);
    // max_here_document(max_here_document_val);
    // printf("max_here_document_val: %d\n", max_here_document_val);
    while (redirection)
    {
        redirection = redirection->next;
    }
}
