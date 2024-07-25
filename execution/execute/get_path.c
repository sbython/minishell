/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/17 11:45:46 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	full_string(t_env *env, char *str)
{
	char	**r;
	int		i;

	(void)env;
	i = 0;
	r = ft_split(str, ':');
}

void	get_vale_from_path(t_env *env, char *vale)
{
	int		i;
	int		start;
	char	*str;
	int		k;

	str = malloc(ft_strlen(vale) + 1);
	i = 0;
	start = 0;
	while (vale[i])
	{
		if (vale[i] == ':')
			break ;
		i++;
	}
	start = i + 1;
	k = 0;
	while (vale[start])
	{
		str[k] = vale[start];
		k++;
		start++;
	}
	str[k] = '\0';
	full_string(env, str);
}

char	**get_path(t_env *all_env)
{
	while (all_env)
	{
		if (ft_strncmp(all_env->name, "PATH", 4) == 0)
		{
			get_vale_from_path(all_env, all_env->vale);
		}
		// printf("%s\n", all_env)
		// all_env = all_env->next;
	}
	return (NULL);
}
