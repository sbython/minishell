/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gramer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:57:19 by msbai             #+#    #+#             */
/*   Updated: 2024/07/15 17:03:31 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_token(char *ls, int i)
{
	return (!ls || ((!ft_strncmp(ls, "|", -1) && i) || !ft_strncmp(ls, "<<", -1)
			|| !ft_strncmp(ls, ">>", -1) || !ft_strncmp(ls, "<", -1)
			|| !ft_strncmp(ls, ">", -1)));
}

int	check_gramer(t_box *box)
{
	t_com	*ls;

	ls = box->l_com;
	while (ls)
	{
		if ((ls->next && ls->type > 1 && ls->next->type >= 1) || (!ls->next
				&& ls->type >= 1))
		{
			exit_f("minishell: syntax error near unexpected token ",
				"`<< or >> or < or >'\n",
				box);
			return (1);
		}
		else if (ls->next && ls->type == 1 && ls->next->type == 1)
		{
			exit_f("minishell: syntax error near unexpected token ",
				"`<< or >> or < or >'\n",
				box);
			return (1);
		}
		ls = ls->next;
	}
	return (0);
}
