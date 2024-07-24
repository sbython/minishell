/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:37 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 19:52:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*add_new_var(char *name, char *vale)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
	{
		perror("allocation error");
		return (NULL);
	}
	lst->name = ft_strdup(name);
	lst->vale = ft_strdup(vale);
	lst->next = NULL;
	return (lst);
}

t_env	*last_n(t_env *node)
{
	if (!node)
		return (NULL);
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	add_back(t_env **node, t_env *new)
{
	t_env	*last;

	if (!*node)
	{
		*node = new;
		return ;
	}
	last = last_n(*node);
	last->next = new;
}

/*
	*name  	tabl[0]
	*vale 	tbl[1]
	*new	tb[2]
*/
t_env	*fill_env(char **en)
{
	int		i;
	t_env	*lst;
	char	*tbl[3];

	i = 0;
	lst = NULL;
	while (en[i])
	{
		tbl[2] = ft_strdup(en[i]);
		tbl[0] = tbl[2];
		tbl[1] = ft_strchr(tbl[2], '=');
		*tbl[1] = 0;
		tbl[1]++;
		add_back(&lst, add_new_var(tbl[0], tbl[1]));
		free(tbl[2]);
		i++;
	}
	return (lst);
}
