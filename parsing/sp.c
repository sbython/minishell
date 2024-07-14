/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:49:24 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 09:07:22 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	kmala(char *s, int i)
{
	char ch;

	ch = s[i];
	i++;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == '\'' || s[i] == '"')
		i++;
	return (i);
}

void	for25line(t_com **list, t_box *ls, t_com *last, t_com **n_box)
{
	t_com	*tmp;

	tmp = *list;
	if ((*list)->prev)
	{
		(*list)->prev->next = ls->l_com;
		ls->l_com->prev = (*list)->prev;
	}
	else
		(*n_box) = ls->l_com;
	free(tmp->com);
	free(tmp);
	if (last)
	{
		tmp = last_node(ls->l_com);
		last->prev = tmp;
		tmp->next = last;
	}
	(*list) = ls->l_com;
}

void	sp(t_com **list, char *str, t_com *last, t_com **n_box)
{
	char	**ptr;
	t_box	*ls;

	ls = malloc(sizeof(t_box));
	ptr = ft_newsplit(str);
	fill_list(ptr, ls);
	free_2ptr(ptr);
	for25line(list, ls, last, n_box);
	while (ls->l_com)
	{
		ls->l_com->type = 0;
		ls->l_com = ls->l_com->next;
	}
	free(ls);
	free(str);
}
