/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/25 17:22:25 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	notn(char *n)
{
	int	i;

	i = 0;
	if (!n)
		return (0);
	else if (n[i] == '-')
		i++;
	else
		return (0);
	while (n[i])
	{
		if (n[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	next_(char **s)
{
	int	i;

	i = 1;
	while (notn(s[i]))
		i++;
	return (i);
}

int	rebuild_echo(char **ptr)
{
	int	i;

	(void)ptr;
	i = next_(ptr);
	while (ptr && ptr[i])
	{
		printf("%s", ptr[i]);
		i++;
		if (ptr[i])
			printf(" ");
	}
	if (!notn(ptr[1]) || !ptr[1])
		printf("\n");
	return (0);
}
