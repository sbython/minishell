/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/02 19:47:28 by zibnoukh         ###   ########.fr       */
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

int    execute(t_box *box)
{
    char** files;
    files = NULL;
    int status;

    status = 0;
    if(sizeee(box) == 1 && box->node->command->options && put_builtins(box->node->command->options[0]))
        status = builtins(box->node->command->options, box, 1);
    else if(sizeee(box) == 1 && box->node->command->redirection)
    {
        files = run_all_heardocs(box);
        ft_redirection(box, box->node->command->redirection, files[0], 0);
    }
    else
        status = more_then___(box);
    return status;
}
