/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/17 11:25:14 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    redirection(t_box *box)
{
    box->done_heardoc = 0;
    
    while(box->node->command->redirection)
    {
        if(box->node->command->redirection->flag == 4)
            left_shift(box, box->node->command->redirection->str);
        // if(box->done_heardoc)
        // {
            // if(box->node->command->redirection->flag == 3)
                // greater_than_sign(box, box->node->command->redirection->str);
            // else if(box->node->command->redirection->flag == 2)
                // less_than_sign(box, box->node->command->redirection->str);
            // else if(box->node->command->redirection->flag == 5)
                // right_shift(box, box->node->command->redirection->str);
        // }
        box->node->command->redirection = box->node->command->redirection->next;
    }
}
