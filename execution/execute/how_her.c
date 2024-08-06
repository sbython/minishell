/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_her.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/30 10:07:03 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int     how_her(t_box *box)
{
    int count = 0;
    t_command* tmp = box->node->command;
    while (tmp)
    {
        t_redirection *red = box->node->command->redirection;
        while (red)
        {
            if(red->flag == 4)
                count++;
            red = red->next;
        }
        tmp = tmp->next;
    }
    if(count > 16)
    {
        printf("maximum here-document count exceeded\n");
        exit(0);
    }
    return count;
}
