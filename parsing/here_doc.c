/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:00:23 by msbai             #+#    #+#             */
/*   Updated: 2024/07/15 17:03:49 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_it(char *str)
{
	char	*delimiter;

	delimiter = ft_strdup("ok");
	while (delimiter)
	{
		free(delimiter);
		delimiter = readline(">");
		if (!delimiter)
			break ;
		else if (!ft_strncmp(delimiter, str, -1))
		{
			free(delimiter);
			break ;
		}
	}
	return (1);
}

void	while_it(t_box *box)
{
	t_com	*ls;

	ls = box->l_com;
	while (ls)
	{
		if (!ft_strncmp(ls->com, "<<", 3) && ls->next
			&& ft_strncmp(ls->next->com, "<<", 3))
		{
			open_it(ls->next->com);
		}
		ls = ls->next;
	}
}

int	open_here_doc(t_box *box)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	else if (pid == 0)
	{
		handlesignal(2, box);
		while_it(box);
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			box->exit_val = 130;
		return (0);
	}
	return (1);
}
