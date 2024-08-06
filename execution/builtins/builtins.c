/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/02 12:42:11 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtins(char **ptr, t_box *box)
{
	int	status;

	status = 0;
	if (!*ptr)
		status = 127;
	else if (ft_strncmp(ptr[0], "cd", -1) == 0)
		status = rebuild_cd(ptr, box->env);
	else if (ft_strncmp(ptr[0], "echo", -1) == 0)
		status = rebuild_echo(ptr);
	else if (ft_strncmp(ptr[0], "pwd", -1) == 0)
		status = rebuild_pwd(ptr);
	else if (ft_strncmp(ptr[0], "exit", -1) == 0)
		status = rebuild_exit(ptr, box);
	else if (ft_strncmp(ptr[0], "export", -1) == 0)
		status = rebuild_export(ptr, box->env);
	else if (ft_strncmp(ptr[0], "env", -1) == 0)
		status = rebuild_env(box->env);
	else if (ft_strncmp(ptr[0], "unset", -1) == 0)
		status = rebuild_unset(ptr, box);
	return (status);
}
