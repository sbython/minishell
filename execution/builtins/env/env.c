/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 10:28:52 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_env(t_box *box)
{
    t_env *env__ = box->env;

    while (env__ != NULL)
    {
        ft_putstr_fd(env__->name, 1);
        ft_putstr_fd("=", 1);
        ft_putstr_fd(env__->vale, 1);
        ft_putstr_fd("\n", 1);
        env__ = env__->next;
    }
}
