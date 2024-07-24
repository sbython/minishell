/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 09:29:33 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_cd(t_box *box)
{
    t_command *boxy = box->node->command;
    if(boxy->options[0] && ! boxy->options[1])
    {
        boxy->options[1] = getenv("HOME");
        if (boxy->options[1] == NULL)
        {
            printf("cd: HOME not set\n");
            return ;
        }
    }

    if (chdir(boxy->options[1]) != 0)
    {
        perror("cd failed");
        return ;
    }
}
