/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:10:39 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 08:24:50 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	func(t_com *com)
{
	if (!ft_strncmp(com->com, "|", -1))
		com->type = 1;
	else if (!ft_strncmp(com->com, "<", -1))
		com->type = 2;
	else if (!ft_strncmp(com->com, ">", -1))
		com->type = 3;
	else if (!ft_strncmp(com->com, "<<", -1))
		com->type = 4;
	else if (!ft_strncmp(com->com, ">>", -1))
		com->type = 5;
	else
		com->type = 0;
}

void	put_type(t_box *box)
{
	t_com	*com;

	com = box->l_com;
	while (com)
	{
		func(com);
		com = com->next;
	}
}
