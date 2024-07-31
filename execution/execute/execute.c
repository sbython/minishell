/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/31 19:12:57 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int sizeee(t_box *box)
{
	int count = 0;
	if (!box || !box->node || !box->node->command) 
        return count;
	t_command* curr = box->node->command;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return count;
}

void	execute(t_box *box)
{
	if(sizeee(box) == 1 && put_builtins(box->node->command->options[0]) && !box->node->command->redirection)
		builtins(box->node->command->options, box);
	else
		more_then___(box);
}
