/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 16:04:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	rebuild_env(t_env *env__)
{
	t_env	*tampy__;

	tampy__ = env__->theEponew;
	while (tampy__ != NULL)
	{
		if (tampy__->vale)
		{
			ft_putstr_fd(tampy__->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(tampy__->vale, 1);
			ft_putstr_fd("\n", 1);
		}
		tampy__ = tampy__->next;
	}
	return (0);
}
