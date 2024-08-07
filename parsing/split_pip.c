/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:11:36 by msbai             #+#    #+#             */
/*   Updated: 2024/07/15 18:18:48 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	slen(char *str)
{
	int		i;
	char	c;

	i = 1;
	c = *str;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\'' || str[i] == '"')
		i++;
	return (i);
}

char	*new_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!*s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			i += slen(s + i);
		else if ((char)c == s[i] && (char)c == s[i + 1])
			return (NULL);
		else if ((char)c == s[i])
			return ((char *)(&s[i]));
		else
			i++;
	}
	if ((char)c == s[i])
		return ((char *)(&s[i]));
	return (NULL);
}

char	*new_strnstr(char *str, char *str1)
{
	size_t	i;
	size_t	i1;

	i = 0;
	i1 = 0;
	if (!str)
		return (NULL);
	if (!*str1)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			i += slen(str + i);
		if (!str[i])
			break ;
		while (str[i + i1] && str1[i1] && str[i + i1] == str1[i1])
			i1++;
		if (!str1[i1])
			return ((char *)(str + i));
		i1 = 0;
		i++;
	}
	return (NULL);
}

int	catit(t_com *com, char *pip1)
{
	t_com	*next;
	t_com	*node;
	t_com	*pip;
	char	*new;

	next = com->next;
	new = new_strnstr(com->com, pip1);
	*new = 0;
	new += ft_strlen(pip1);
	new = ft_strdup(new);
	node = new_node(new);
	node->next = next;
	pip = new_node(ft_strdup(pip1));
	com->next = pip;
	pip->prev = com;
	pip->next = node;
	node->prev = pip;
	return (1);
}

void	split_pip(t_box *box)
{
	t_com	*com;
	int		f;

	com = box->l_com;
	f = 0;
	while (com)
	{
		if (new_strchr(com->com, '|') && ft_strncmp(com->com, "|", -1))
			f = catit(com, "|");
		else if (new_strchr(com->com, '<') && ft_strncmp(com->com, "<", -1))
			f = catit(com, "<");
		else if (new_strchr(com->com, '>') && ft_strncmp(com->com, ">", -1))
			f = catit(com, ">");
		else if (new_strnstr(com->com, ">>") && ft_strncmp(com->com, ">>", -1))
			f = catit(com, ">>");
		else if (new_strnstr(com->com, "<<") && ft_strncmp(com->com, "<<", -1))
			f = catit(com, "<<");
		else
			com = com->next;
		if (f && com->prev)
		{
			com = com->prev;
			f = 0;
		}
	}
}
