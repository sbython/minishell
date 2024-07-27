/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 18:55:00 by zibnoukh         ###   ########.fr       */
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
	t_env	*new = NULL;
	t_env	*niiiv = NULL;
	int status = 0;

	arr[0] = NULL;
	arr[1] = NULL;
	i = 1;
	while (ptr[i])
	{
		niiiv = env;
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
					  	new->vale = arr[1];
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
		if(arr[0])
			free(arr[0]);
		if(arr[1])
			free(arr[1]);
		i++;
	}
	return status;
}

int	rebuild_export(char **ptr, t_env *env)
{
	t_env	*newenv = NULL;
	t_env	*tmp_env = NULL;
	int status = 0;

	status = add_one(ptr, env);

	if (!ptr[1])
	{
		newenv = sort_env(env);
		tmp_env = newenv;
		while (newenv != NULL)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(newenv->name, 1);
			if (newenv->vale)
				printf("=\"%s\"", newenv->vale);
			printf("\n");
			newenv = newenv->next;
		}
		free_env(tmp_env);
	}
	return (status);
}
