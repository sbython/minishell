/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/25 13:31:17 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

size_t	ft_latoi(const char *num)
{
	size_t	i;
	size_t	res;
	size_t	sing;

	i = 0;
	res = 0;
	sing = 1;
	while ((num[i] >= 9 && num[i] <= 13) || num[i] == 32)
	{
		i++;
	}
	if (num[i] == '-')
	{
		i++;
		sing = -1;
	}
	else if (num[i] == '+')
		i++;
	while (num[i] <= '9' && num[i] >= '0')
		res = (res * 10) + num[i++] - '0';
	return (res * sing);
}

int	not_numeric(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	rebuild_exit(char **ptr, t_box *box)
{
	ssize_t	c;

	ft_putstr_fd("exit\n", 1);
	if (ptr[1])
		c = ft_latoi(ptr[1]);
	else
		c = 0;
	if (c < (ssize_t)LONG_MIN || c > (ssize_t)LONG_MAX || (ptr[1]
			&& ft_strlen(ptr[1]) > 20))
		ft_putendl_fd("exit: numeric argument required", 2);
	else if (ptr[2] && ptr[1] && !not_numeric(ptr[1]))
	{
		ft_putendl_fd("bash: exit: too many arguments", 2);
		return (1);
	}
	else if (ptr[1] && not_numeric(ptr[1]))
		ft_putendl_fd("exit: numeric argument required", 2);
	if (not_numeric(ptr[1]) || c < (ssize_t)LONG_MIN || c > (ssize_t)LONG_MAX
		|| (ptr[1] && ft_strlen(ptr[1]) > 20))
		c = 2;
	free_all(box);
	rl_clear_history();
	free_env(box->env);
	exit((unsigned char)c);
	return (0);
}
