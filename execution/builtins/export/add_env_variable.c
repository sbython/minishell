/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 17:17:28 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_env	*create_env_node(char *name, char *value)
{
	t_env	*new_node;
	
	if (!name)
		return (NULL);
	new_node = NULL;
	new_node = malloc(sizeof(t_env));
	if (!new_node)
	{
		perror("error");
		exit(0);
	}
	new_node->name = ft_strdup(name);
	new_node->vale = ft_strdup(value);
	new_node->next = NULL;
	return (new_node);
}

t_env	*find_last_node(t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	add_env_variable(t_env *env, char *name, char *value)
{
	t_env	*new_node;
	t_env	*last;

	new_node = create_env_node(name, value);
	last = find_last_node(env);
	last->next = new_node;
}
