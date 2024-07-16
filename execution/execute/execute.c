/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/16 15:58:56 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    length_opp(char **opp)
{
    int i;

    i = 0;
    while (opp[i])
        i++;
    return i;
}

void    execute(t_box *box)
{
    // char** r = get_path(box->env);
    while (box->node->command)
    {
        int i = 0;
        while (box->node->command->options[i])
        {
            printf("%s", box->node->command->options[i]);
            // f(box);
            i++;
        }
        printf("\n");
        box->node->command = box->node->command->next;
    }
}
