/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 19:06:07 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int    rebuild_env(char **ptr, t_env *env__)
{
    (void)ptr;
    while (env__ != NULL)
    {
        if(env__->vale)
        {
            ft_putstr_fd(env__->name, 1);
            ft_putstr_fd("=", 1);
            ft_putstr_fd(env__->vale, 1);
            ft_putstr_fd("\n", 1);
        }
        env__ = env__->next;
    }
    return 0;
}
