/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/15 14:52:22 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_env(t_env *all_env)
{
    while (all_env)
    {
        ft_putstr_fd(all_env->name, 1);
        ft_putstr_fd("=", 1);
        ft_putstr_fd(all_env->vale, 1);
        ft_putstr_fd("\n", 1);
        all_env = all_env->next;
    }
}
