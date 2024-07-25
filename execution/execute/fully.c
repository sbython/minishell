/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fully.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:34:21 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/17 13:49:47 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*fully(char **r, char *cmd)
{
	int		i;
	char	*str;

	i = 0;
	while (r[i] != NULL)
	{
		str = ft_strjoin(r[i], ft_strjoin("/", cmd));
		if (access(str, X_OK) == 0)
			return (str);
		i++;
	}
	return (NULL);
}
