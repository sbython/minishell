/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 16:16:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_unset(t_box *box)
{
    char* name;
    t_env *current;
    t_env *previous;

    if(box->node->command->options[1])
    {
        name = filter_v(box->node->command->options[1]);
        current = box->env;
        previous = NULL;

        while (current != NULL && ft_strncmp(current->name, name, ft_strlen(name)) != 0) 
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
}
