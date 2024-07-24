/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 19:10:37 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute(t_box *box)
{
//     int i;

//     while (box->node->command)
//     {
//         i = 0;
        
//         while (box->node->command->options[i])
//         {
//             printf("%s\n", box->node->command->options[i]);
//             i++;
//         }
        
//         box->node->command = box->node->command->next;
//     }

//     printf("i: %d\n", i);
	// more_then___(box);
	builtins(box->node->command->options, box->env);
}
