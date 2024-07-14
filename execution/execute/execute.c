/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 10:12:51 by zibnoukh         ###   ########.fr       */
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
    (void)box;
    // printf("length of OPP: %d\n", length_opp(box->node->command->options));
    if(!box->node->command->redirection)
        execute_c_options(box);
    else
        printf("IS DATA\n");
}
