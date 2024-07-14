/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 08:21:33 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	nongnu(int i)
{
	if (i == SIGINT)
	{
		write(0, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handlesignal(int i)
{
	if (i)
	{
		signal(SIGINT, nongnu);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	shell_loop(char **en)
{
	char	*prom;
	t_box	lst;

	(void)en;
	ft_memset((void *)&lst, 0, sizeof(t_box));
	lst.getpid = get_pid();
	lst.env = fill_env(en);
	while (1)
	{
		handlesignal(1);
		prom = prompt();
		lst.cmd = readline(prom);
		handlesignal(0);
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
