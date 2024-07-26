/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/26 10:39:26 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	rebuild_env(char **ptr, t_env *env__)
{
	t_env	*tampy__;

	(void)ptr;
	tampy__ = env__;
	while (tampy__ != NULL)
	{
		if (tampy__->vale && ft_strlen(tampy__->vale) != 0)
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
