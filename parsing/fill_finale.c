/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_finale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:56:03 by msbai             #+#    #+#             */
/*   Updated: 2024/08/02 18:46:58 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	take_it(t_redirection **re, t_com *ls)
{
	t_redirection	*last_re;
	t_redirection	*new_re;

	last_re = *re;
	while (last_re && last_re->next)
	{
		last_re = last_re->next;
	}
	new_re = ft_calloc(1, sizeof(t_redirection));
	new_re->flag = ls->prev->type;
	new_re->str = ls->com;
	new_re->next = NULL;
	if (last_re)
		last_re->next = new_re;
	else
		*re = new_re;
}

void	for25line2(t_com **ls, t_command **command)
{
	if ((*ls)->type < 1 )
		(*command)->options = join2pointer((*command)->options, (*ls)->com);
	else if ((*ls)->type > 1)
	{
		(*ls) = (*ls)->next;
		take_it(&(*command)->redirection, (*ls));
	}
	else if ((*ls)->type == 1)
	{
		(*command)->next = ft_calloc(1, sizeof(t_command));
		(*command) = (*command)->next;
		(*command)->next = NULL;
	}
}

void	fill_finale(t_box *box)
{
	t_com		*ls;
	t_node		*node_;
	t_command	*command;

	node_ = ft_calloc(1, sizeof(t_node));
	node_->command = ft_calloc(1, sizeof(t_command));
	box->node = node_;
	ls = box->l_com;
	command = node_->command;
	command->next = NULL;
	while (ls)
	{
		for25line2(&ls, &command);
		ls = ls->next;
	}
}
