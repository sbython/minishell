/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:26:19 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/22 09:55:36 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int    get_cmd(t_box *box)
{
    t_com *ls;

    ls = NULL;   

    
    if(!box->cmd)
    {
        printf("exit\n");
        box->exit_val = 0;
        return (1);
    }
    if (parsing(box))
        return 0;

    fill_finale(box);
    ls = box->l_com;
    execute(box);
    // free_node(box->node);
    return (0);
}
