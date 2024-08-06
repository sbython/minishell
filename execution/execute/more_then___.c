/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/06 14:30:12 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	more_then___(t_box *box)
{
	int			fd[2];
	int			prev_fd;
	int			pid;
	t_command	*cmd;
	int			i;
	int			Getfd_input__;
				int Getfd_output__;

	prev_fd = -1;
	pid = 0;
	cmd = box->node->command;
	i = 0;
	cmd->files = NULL;
	if (run_all_heardocs(cmd, box))
		return (box->exit_val);
	while (box->node->command)
	{
		if (box->node->command->next)
		{
			if (pipe(fd) == -1)
			{
				perror("pipe failed");
				exit(1);
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			handlesignal(2, box);
			ft_redirection(box->node->command, box->node->command->redirection,
				box->node->command->files[i], 1);
			if (box->node->command->input_file)
			{
				Getfd_input__ = open(box->node->command->input_file, O_RDONLY);
				if (Getfd_input__ == -1 || dup2(Getfd_input__, 0) == -1)
				{
					perror("dup2 input failed");
					exit(1);
				}
				close(Getfd_input__);
			}
			else if (prev_fd != -1)
			{
				if (dup2(prev_fd, 0) == -1)
				{
					perror("dup2 prev_fd failed");
					exit(1);
				}
				close(prev_fd);
			}
			if (box->node->command->output_file)
			{
				if (box->node->command->append)
					Getfd_output__ = open(box->node->command->output_file,
							O_CREAT | O_WRONLY | O_APPEND, 0666);
				else
					Getfd_output__ = open(box->node->command->output_file,
							O_CREAT | O_WRONLY | O_TRUNC, 0666);
				if (Getfd_output__ == -1 || dup2(Getfd_output__, 1) == -1)
				{
					perror("dup2 output failed");
					exit(1);
				}
				close(Getfd_output__);
			}
			else if (box->node->command->next)
			{
				if (dup2(fd[1], 1) == -1)
				{
					perror("dup2 fd[1] failed");
					exit(1);
				}
				close(fd[1]);
			}
			exe_cvee(box);
		}
		if (prev_fd != -1)
			close(prev_fd);
		if (box->node->command->next)
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
		i++;
		box->node->command = box->node->command->next;
	}
	while (wait(NULL) > 0)
	{
	};
	return (0);
}
