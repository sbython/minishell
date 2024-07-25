/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/25 17:12:08 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_env	*create_env_node(char *name, char *value)
{
	t_env	*new_node;

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

int	rebuild_export(char **ptr, t_env *env)
{
	char	*new_name;
	char	*new_vale;
	t_env	*tmp_env;
	int		i;

	tmp_env = env;
	i = 1;
	while (ptr[i])
	{
		new_vale = filter_v(ptr[i]);
		new_name = filter_n(ptr[i]);
		add_env_variable(env, new_vale, new_name);
		i++;
	}
	sort_env(tmp_env);
	if (!ptr[1])
	{
		while (tmp_env != NULL)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(tmp_env->name, 1);
			if (tmp_env->vale && ft_strlen(tmp_env->vale) != 0)
				ft_putstr_fd("=", 1);
			ft_putstr_fd(tmp_env->vale, 1);
			ft_putstr_fd("\n", 1);
			tmp_env = tmp_env->next;
		}
	}
	return (0);
}
