/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 04:45:20 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/20 18:10:28 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	t_com	*l;

	ls = malloc(sizeof(t_box));
	ptr = ft_newsplit(str);
	fill_list(ptr, ls);
	free_2ptr(ptr);
	l = ls->l_com;
	while (l)
	{
		l->type = 0;
		l = l->next;
	}
	for25line(list, ls, last, n_box);
	free(ls);
	free(str);
}
