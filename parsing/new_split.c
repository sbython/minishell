/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 05:06:49 by msbai             #+#    #+#             */
/*   Updated: 2024/08/02 13:02:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_newsplit(char *s)
{
	char	**ptr;
	char	*start;
	int		i;

	ptr = NULL;
	i = 0;
	start = s;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			i += slen(s + i);
		else
			i++;
		if (s[i] == ' ' || !s[i])
		{
			if (s[i])
				s[i++] = 0;
			ptr = join2pointer(ptr, ft_strdup(start));
			while (s[i] && s[i] == ' ')
				i++;
			start = &s[i];
		}
	}
	return (ptr);
}
