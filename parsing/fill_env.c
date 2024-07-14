/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:37 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 08:40:52 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

env	*add_new_var(char *name, char *vale)
{
	env	*lst;

	lst = malloc(sizeof(env));
	if (!lst)
	{
		perror("allocation error");
		return (NULL);
	}
	lst->name = name;
	lst->vale = vale;
	lst->next = NULL;
	return (lst);
}

env	*last_n(env *node)
{
	if (!node)
		return (NULL);
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	add_back(env **node, env *new)
{
	env	*last;

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
env	*fill_env(char **en)
{
	int		i;
	env		*lst;
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
		i++;
	}
	return (lst);
}
