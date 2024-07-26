/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/26 15:16:42 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	add_one(char **ptr, t_env *env)
{
	int		i;
	char	*arr[2];
	t_env	*new;

	i = 1;
	while (ptr[i])
	{
		arr[0] = filter_v(ptr[i]);
		arr[1] = filter_n(ptr[i]);
		new = envchr(env, arr[0]);
		if (new)
		{
			if (arr[1])
			{
				free(new->vale);
				new->vale = arr[1];
			}
		}
		else
			add_env_variable(env, arr[0], arr[1]);
		i++;
	}
}

int	rebuild_export(char **ptr, t_env *env)
{
	t_env	*newenv;
	t_env	*tmp_env;

	tmp_env = env;
	add_one(ptr, env);
	newenv = sort_env(tmp_env);
	if (!ptr[1])
	{
		while (newenv != NULL)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(newenv->name, 1);
			if (newenv->vale)
				printf("=\"%s\"", newenv->vale);
			printf("\n");
			newenv = newenv->next;
		}
	}
	return (0);
}

/* s_cases

	- = for not value
	- replace last value

*/
