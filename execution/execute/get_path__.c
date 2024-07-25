/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path__.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:34:21 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/17 13:49:52 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**full_string__(t_env *env, char *str)
{
	char	**r;
	int		i;

	(void)env;
	i = 0;
	r = ft_split(str, ':');
	return (r);
}

char	**get_vale_from_path__(t_env *env, char *vale)
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
	return (full_string__(env, str));
}

char	**get_path__(t_env *all_env)
{
	while (all_env)
	{
		if (ft_strncmp(all_env->name, "PATH", 4) == 0)
		{
			return (get_vale_from_path__(all_env, all_env->vale));
		}
		all_env = all_env->next;
	}
	return (NULL);
}
