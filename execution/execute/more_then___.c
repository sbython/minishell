/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/31 10:47:08 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void more_then___(t_box *box)
{
    int fd[2];
    char **r;
    char *full_path;
    r = get_path__(box->env);
    int prev_fd = -1;
    int pid;
    char **files = run_all_heardocs(box);
    int i = 0;
    int status = 0;
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
            ft_redirection(box, box->node->command->redirection, files[i]);
            if (box->input_file)
            {
                int Getfd_input__ = open(box->input_file, O_RDONLY);
                if (Getfd_input__ == -1)
                {
                    perror(box->input_file);
                    exit(1);
                }
                if (dup2(Getfd_input__, 0) == -1)
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

            if (box->output_file)
            {
                int Getfd_output__;
                if (box->append)
                    Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
                else
                    Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
                if (Getfd_output__ == -1)
                {
                    perror(box->output_file);
                    exit(1);
                }
                if (dup2(Getfd_output__, 1) == -1)
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

            full_path = fully(r, box->node->command->options[0]);
            if (!full_path)
            {
                printf("Command '%s' not found\n", box->node->command->options[0]);
                exit(0);
            }
            if (execve(full_path, box->node->command->options, box->full_env) == -1)
            {
                perror("execve failed");
                exit(1);
            }
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

    while (waitpid(pid, &status, 0) > 0);
}
