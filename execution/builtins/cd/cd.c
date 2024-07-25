/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/25 17:19:28 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_env	*envchr(t_env *env__, char *name)
{
	while (env__)
	{
		if (!ft_strncmp(env__->name, name, -1))
			return (env__);
		env__ = env__->next;
	}
	return (NULL);
}

void	update_env(t_env *env__)
{
	t_env	*pwd;
	t_env	*old_pwd;
	char	tmp[1000];

	pwd = envchr(env__, "PWD");
	old_pwd = envchr(env__, "OLDPWD");
	if (old_pwd)
	{
		free(old_pwd->vale);
		old_pwd->vale = pwd->vale;
	}
	if (pwd)
	{
		getcwd(tmp, 1000);
		pwd->vale = ft_strdup(tmp);
	}
}

int	rebuild_cd(char **ptr, t_env *env__)
{
	if (ptr[0] && !ptr[1])
	{
		ptr[1] = (envchr(env__, "HOME"))->vale;
		if (ptr[1] == NULL)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
	}
	if (chdir(ptr[1]) != 0)
	{
		perror("cd failed");
		return (1);
	}
	update_env(env__);
	return (0);
}
