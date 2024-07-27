/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 14:48:21 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int check_plus(char *str, int size_name)
{
	if(str[size_name] == '+' && str[size_name + 1] == '=')
		return 1;
	else
		return 0;
}

int	add_one(char **ptr, t_env *env)
{
	int		i;
	char	*arr[2];
	t_env	*new;
	int status = 0;

	i = 1;
	while (ptr[i])
	{
		arr[0] = filter_n(ptr[i]);
		if(ft_utils(ptr[i]))
		{
			arr[1] = filter_v(ptr[i]);
			new = envchr(env, arr[0]);
			if (new != NULL)
			{
				if(check_plus(ptr[i], ft_strlen(filter_n(ptr[i]))))
				{
					new->vale = ft_strjoin(new->vale, arr[1]);
					new->name = filter_n(arr[0]);
				}
				else
				{
					if (arr[1])
					{
					  	new->vale = arr[1];
					}
				}
			}
			else
				add_env_variable(env, arr[0], arr[1]);
		}
		else
		{
			printf("export: `%s': not a valid identifier\n", ptr[i]);
			status = 1;
		}
		i++;
	}
	return status;
}

int	rebuild_export(char **ptr, t_env *env)
{
	t_env	*newenv;
	t_env	*tmp_env;
	int status = 0;

	tmp_env = env;
	status = add_one(ptr, env);
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
	return (status);
}
