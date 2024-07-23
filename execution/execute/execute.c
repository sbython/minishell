/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/23 10:13:01 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	execute(t_box *box)
// {
//     char** r = get_path__(box->env);
//     while (box->node->command)
//     {
//         int pid;

//         pid = fork();
//         if(pid == -1)
//         {
//             perror("failed");
//             exit(0);
//         }
//         else if(pid == 0)
//         {
//             ft_redirection(box, box->node->command->redirection);
//             t_redirection *rd = box->node->command->redirection;
//             open_all_files(rd);

//             if(box->input_file)
//             {
//                 int Getfd_input__ = open(box->input_file, O_RDONLY, 0666);
//                 if(Getfd_input__ == -1)
//                 {
//                     perror(box->input_file);
//                     exit(0);
//                 }
//                 if(dup2(Getfd_input__, 0) == -1)
//                 {
//                     perror("dup 1 faled");
//                     exit(0);
//                 }
//             }

//             if(box->output_file)
//             {
//                 int Getfd_output__;
//                 if(box->append == 400)
//                 {
//                     Getfd_output__ = open(box->output_file,
		// O_CREAT | O_WRONLY | O_APPEND, 0666);
//                 }
//                 if(!box->append)
//                 {
//                     Getfd_output__ = open(box->output_file,
		// O_CREAT | O_WRONLY | O_TRUNC, 0666);
//                 }
//                 if(dup2(Getfd_output__, 1) == -1)
//                 {
//                     perror("dup 2 faled");
//                     exit(0);
//                 }
//             }

//             char *full_path = fully(r, box->node->command->options[0]);
//             if((execve(full_path, box->node->command->options,
			// box->full_env) == -1))
//             {
//                 ft_putstr_fd("file not found\n", 2);
//                 exit(0);
//             }
//         }
//         box->node->command = box->node->command->next;
//     }
//     while (wait(NULL) > 0);
// }

// *******************************************

void	execute(t_box *box)
{
	char			**r;
	int				fd[2];
	int				prev_fd;
	int				pid;
	t_redirection	*rd;
	int				Getfd_input__;
	int Getfd_output__;
	char			*full_path;

	r = get_path__(box->env);
	prev_fd = -1;
	while (box->node->command)
	{
		ft_redirection(box, box->node->command->redirection);
		if (box->node->command->next)
		{
			if (pipe(fd) == -1)
			{
				perror("pipe failed");
				exit(EXIT_FAILURE);
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			// if(move)
            // {
                    rd = box->node->command->redirection;
                    open_all_files(rd);
                    if (box->input_file)
                    {
                        Getfd_input__ = open(box->input_file, O_RDONLY);
                        if (Getfd_input__ == -1)
                        {
                            perror(box->input_file);
                            exit(EXIT_FAILURE);
                        }
                        if (dup2(Getfd_input__, 0) == -1)
                        {
                            perror("dup2 input failed");
                            exit(EXIT_FAILURE);
                        }
                        close(Getfd_input__);
                    }
                    else if (prev_fd != -1)
                    {
                        if (dup2(prev_fd, 0) == -1)
                        {
                            perror("dup2 prev_fd failed");
                            exit(EXIT_FAILURE);
                        }
                        close(prev_fd);
                    }
                    if (box->output_file)
                    {
                        if (box->append)
                        {
                            Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
                        }
                        else
                        {
                            Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
                        }
                        if (Getfd_output__ == -1)
                        {
                            perror(box->output_file);
                            exit(EXIT_FAILURE);
                        }
                        if (dup2(Getfd_output__, 1) == -1)
                        {
                            perror("dup2 output failed");
                            exit(EXIT_FAILURE);
                        }
                        close(Getfd_output__);
                    }
                    else if (box->node->command->next)
                    {
                        if (dup2(fd[1], 1) == -1)
                        {
                            perror("dup2 fd[1] failed");
                            exit(EXIT_FAILURE);
                        }
                        close(fd[1]);
                    }
                    full_path = fully(r, box->node->command->options[0]);
                    if (execve(full_path, box->node->command->options, box->full_env) ==
                        -1)
                    {
                        perror("execve failed");
                        exit(EXIT_FAILURE);
                    }
                }
                if (prev_fd != -1)
                {
                    close(prev_fd);
                }
                if (box->node->command->next)
                {
                    close(fd[1]);
                    prev_fd = fd[0];
                }
                box->node->command = box->node->command->next;
            }
	// }
	while (wait(NULL) > 0)
		;
}
