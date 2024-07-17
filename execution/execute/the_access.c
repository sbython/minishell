/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:48 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/17 11:54:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char *the_access(t_box*box,  char **r)
{
    int i = 0;
    while(r[i] != NULL)
    {
        char *str = ft_strjoin(r[i], ft_strjoin("/", box->node->command->options[0]));
        if (access(str, X_OK) == 0)
            return (str);
        i++;
    }
    return (NULL);
}
