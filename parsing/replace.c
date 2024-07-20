/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:11:59 by msbai             #+#    #+#             */
/*   Updated: 2024/07/20 18:10:17 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_dstr(const char *s, char *c)
{
	int	i;
	int	f;

	f = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			f *= -1;
		else if (s[i] == '\'' && f == 1)
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (!s[i])
				return (NULL);
		}
		if (!ft_strncmp(&s[i], c, ft_strlen(c) - 1))
			return ((char *)(&s[i]));
		i++;
	}
	return (NULL);
}

/*
  * rep_len = len[0]
  * with_len = len[1]
  * len = len[2]
  * result = str[0]
  * res_pos = str[1]
  * pos = str[2]
*/

char	*str_replace(char *s1, char *rep, char *with)
{
	size_t	len[3];
	char	*str[4];

	if (!rep || !*rep)
		return (s1);
	len[0] = ft_strlen(rep);
	len[1] = ft_strlen(with);
	str[0] = ft_calloc(ft_strlen(s1) + (len[1] - len[0]) + 1, sizeof(char));
	str[3] = s1;
	str[1] = str[0];
	str[2] = ft_dstr(s1, rep);
	len[2] = str[2] - s1;
	ft_memcpy(str[1], s1, len[2]);
	str[1] += len[2];
	ft_memcpy(str[1], with, len[1]);
	str[1] += len[1];
	s1 = str[2] + len[0];
	ft_strlcpy(str[1], s1, -1);
	free(str[3]);
	return (str[0]);
}

int	ft_isdelimiter(char *str)
{
	return (!ft_strncmp(str, "<", -1) || !ft_strncmp(str, "<<", -1)
		|| !ft_strncmp(str, ">", -1) || !ft_strncmp(str, ">>", -1));
}

char	*ft_dchr(const char *s, int c)
{
	int	i;
	int	f;

	f = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			f *= -1;
		else if (s[i] == '\'' && f == 1)
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (!s[i])
				return (NULL);
		}
		if ((char)c == s[i])
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == s[i])
		return ((char *)(&s[i]));
	return (NULL);
}

void	tap_to_space(char *s)
{
	int		i;
	char	ch;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			ch = s[i];
			i++;
			while (s[i] && s[i] != ch)
				i++;
			if (s[i] == '\'' || s[i] == '"')
				i++;
		}
		else if (s[i] == '\t')
			s[i] = ' ';
		else
			i++;
	}
}
