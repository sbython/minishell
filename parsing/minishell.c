/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 14:47:30 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		g_status;

void	nongnu(int i)
{
	if (i == SIGINT)
	{
		write(0, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_status = 130;
	}
}

void	handlesignal(int i, t_box *lst)
{
	if (i == 1)
	{
		signal(SIGINT, nongnu);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (i == 2)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	if (g_status == 130)
		lst->exit_val = g_status;
	g_status = 0;
}

void	shell_loop(char **en)
{
	char	*prom;
	t_box	lst;

	(void)en;
	ft_memset((void *)&lst, 0, sizeof(t_box));
	lst.env = fill_env(en);
	while (1)
	{
		prom = prompt();
		handlesignal(1, &lst);
		lst.cmd = readline(prom);
		handlesignal(3, &lst);
		free(prom);
		if (lst.cmd && ft_strncmp(lst.cmd, "", -1))
			add_history(lst.cmd);
		tap_to_space(lst.cmd);
		if (get_cmd(&lst))
			break ;
		free_all(&lst);
	}
	rl_clear_history();
	free_env(lst.env);
	exit(lst.exit_val);
}
#include <sys/time.h>

long get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	main(int ac, char **av, char **env)
{

	(void)av;
	if (ac != 1)
	{
		write(1, "mimishell has no need any arg", 30);
		return (1);
	}
	shell_loop(env);
	return (0);
}
