/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/02 14:47:06 by zibnoukh         ###   ########.fr       */
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
	char** files;
	files = NULL;
	if(sizeee(box) == 1 && box->node->command->options && put_builtins(box->node->command->options[0]))
		builtins(box->node->command->options, box);
	else if(sizeee(box) == 1 && box->node->command->redirection)
	{
		files = run_all_heardocs(box);
		ft_redirection(box, box->node->command->redirection, files[0], 0);
	}
	else
		more_then___(box);
}
