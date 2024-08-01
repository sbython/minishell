/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/01 19:50:24 by zibnoukh         ###   ########.fr       */
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
	// if(!box->node->command->options)
	// {
	// 	ft_putstr_fd("Command '' ", 2);
	// 	ft_putstr_fd("not found\n", 2);
	// 	return;
	// }
	char** files;

	// printf("%s\n", box->node->command->redirection->str);
	files = NULL;
	if(sizeee(box) == 1)
	{
		// && put_builtins(box->node->command->options[0]
		// files = run_all_heardocs(box);
		ft_redirection(box, box->node->command->redirection, files[0], 0);
		// builtins(box->node->command->options, box);
		printf("one cmd\n");
	}
	else
		more_then___(box);
}
