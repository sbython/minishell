/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/25 17:05:55 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	swap_nodes(t_env *a, t_env *b)
{
	char	*tmp_name;
	char	*tmp_vale;

	tmp_name = a->name;
	tmp_vale = a->name;
	a->name = b->name;
	a->vale = b->vale;
	b->name = tmp_name;
	b->vale = tmp_vale;
}

void	sort_env(t_env *env)
{
	t_env	*curr;
	int		is_swap;

	curr = env;
	while (1)
	{
		is_swap = 0;
		curr = env;
		while (curr->next != NULL)
		{
			if (ft_strncmp(curr->name, curr->next->name,
					ft_strlen(curr->name)) > 0)
			{
				swap_nodes(curr, curr->next);
				is_swap = 1;
			}
			curr = curr->next;
		}
		if (!is_swap)
			break ;
	}
}
