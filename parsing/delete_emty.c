/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_emty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:54:14 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/14 08:54:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delete_(t_com *ls)
{
	t_com	*next;
	t_com	*prev;

	next = ls->next;
	prev = ls->prev;
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	free(ls->com);
	free(ls);
}
// <<<<<<< HEAD
// void firs_node(t_box *box)
// {
//     t_com *tmp;
//     char  *str;
    
//     str = box->l_com->com;
//     if(!*str)
//     {
//         tmp = box->l_com->next;
//         free(box->l_com->com);
//         free(box->l_com);
//         box->l_com = tmp;
//         if (tmp)
//             tmp->prev = NULL;
//     }
// }
// void delete_emty(t_box *box)
// {
//     t_com *ls;
//     t_com *tmp;
//     char  *str;
    
//     firs_node(box);
//     ls = box->l_com;
//     while (ls)
//     {
//         str = ls->com;
//         if(!*str)
//         {
//             tmp = ls->next;
//             delete_(ls);
//             ls = tmp;
//         }
//         else
//              ls = ls->next;
//     }
// =======

void	firs_node(t_box *box)
{
	t_com	*tmp;
	char	*str;

	str = box->l_com->com;
	if (!*str)
	{
		tmp = box->l_com->next;
		free(box->l_com->com);
		free(box->l_com);
		box->l_com = tmp;
		box->l_com->prev = NULL;
	}
}

void	rediration(t_com *ls)
{
	t_com	*p;

	ls->prev = NULL;
	while (ls)
	{
		p = ls->next;
		if (p)
			p->prev = ls;
		ls = p;
	}
}

void	delete_emty(t_box *box)
{
	t_com	*ls;
	t_com	*tmp;
	char	*str;

	rediration(box->l_com);
	firs_node(box);
	ls = box->l_com;
	while (ls)
	{
		str = ls->com;
		if (!*str)
		{
			tmp = ls->next;
			delete_(ls);
			ls = tmp;
		}
		else
			ls = ls->next;
	}
}
