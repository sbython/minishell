/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_qoute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:38:13 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 14:58:17 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_(char *str)
{
	char	c;
	int		i;

	i = 0;
	if (!ft_strncmp(str, "\"", -1))
		ft_memset((void *)str, 0, 2);
	while (str[i])
	{
		c = str[i];
		if (c == '"' || c == '\'')
		{
			ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
			str[ft_strlen(str) - 1] = 0;
			while (str[i] && str[i] != c)
				i++;
			if (str[i] == c)
				ft_memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
			str[ft_strlen(str) - 1] = 0;
		}
		else
			i++;
	}
}

void	remove_qoute(t_box *box)
{
	t_com	*ls;

	ls = box->l_com;
	while (ls)
	{
		if (ls->type != -1 && (ft_strchr(ls->com, '\'') || ft_strchr(ls->com, '"')))
			remove_(ls->com);
		ls = ls->next;
	}
}
