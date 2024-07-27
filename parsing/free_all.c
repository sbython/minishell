/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:30 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 18:28:56 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(t_env *lst)
{
	t_env	*tmp;

	while (lst)
	{
		free(lst->name);
		if (lst->vale)
			free(lst->vale);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
}

void	free_lcom(t_com *lst)
{
	t_com	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		free(lst->com);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	free_node(t_node *node)
{
	t_redirection	*tmp;
	t_command		*tmp1;
	t_command		*com;

	if (!node)
		return ;
	com = node->command;
	while (com)
	{
		free(com->options);
		while (com->redirection)
		{
			tmp = com->redirection;
			com->redirection = com->redirection->next;
			free(tmp);
			tmp = NULL;
		}
		tmp1 = com;
		com = com->next;
		free(tmp1);
		tmp1 = NULL;
	}
	free(node);
	node = NULL;
}

void	free_all(t_box *box)
{
	if (box && box->l_com)
	{
		free_lcom(box->l_com);
		box->l_com = NULL;
	}
	if (box && box->cmd)
	{
		free(box->cmd);
		box->cmd = NULL;
	}
	if (box && box->ptr)
	{
		free_2ptr(box->ptr);
		box->ptr = NULL;
	}
}
