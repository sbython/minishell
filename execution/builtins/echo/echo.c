/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 09:29:28 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int     notN(char *n)
{
    int i;

    i = 1;
    while (n[i])
    {
        if(n[i] != 'n')
            return 0;
        i++;
    }
    return 1;
}

void    rebuild_echo(t_box *box)
{
    t_command *boxy = box->node->command;
    int length = 0;
    while (boxy->options[length])
        length++;
    if(boxy->options[0] && !boxy->options[1])
        ft_putstr_fd("\n", 1);
    else
    {
        int i = 1;
        while (boxy->options[i])
        {
            printf("%s", boxy->options[i]);
            if(i < length - 1)
                printf(" ");
            i++;
        }
        if(!notN(boxy->options[1]))
            printf("\n");
    }
}
