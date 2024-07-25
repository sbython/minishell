/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/25 14:53:36 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	free_tmp(t_env *tmp)
{
	free(tmp->name);
	free(tmp->vale);
	free(tmp);
	tmp = NULL;
}

int	rebuild_unset(char **ptr, t_box *box)
{
	t_env	*current;
	t_env	*previous;

	current = NULL;
	previous = NULL;
	if (ptr[1])
	{
		current = box->env;
		while (current != NULL && ft_strncmp(current->name, ptr[1],
				ft_strlen(ptr[1])) != 0)
		{
			previous = current;
			current = current->next;
		}
		if (previous && current)
			previous->next = current->next;
		else if (current)
			box->env = current->next;
	}
	else
		return (0);
	free_tmp(current);
	return (0);
}
