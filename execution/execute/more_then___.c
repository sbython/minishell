/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/04 17:26:49 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int more_then___(t_box *box)
{
    int fd[2];
    int prev_fd = -1;
    int i = 0;
    int j = 0;
    int status = 0;
    if (run_all_heardocs(box))
        return (box->exit_val);
    int the_size = sizeee(box);
    box->pid = malloc(sizeee(box) * sizeof(int *));
    int k = 0;
    while (k < sizeee(box))
        box->pid[k++] = -1;
    box->input_file = NULL;
    box->output_file = NULL;
    t_command* cmd = box->node->command;
    while (cmd)
    {
        if (cmd->next)
        {
            if (pipe(fd) == -1)
            {
                perror("pipe failed");
                exit(1);
            }
        }
        box->pid[j] = fork();
        if (box->pid[j] == -1)
        {
            perror("fork failed");
            exit(1);
        }
        else if (box->pid[j] == 0)
        {
            handlesignal(2, box);
            ft_redirection(box, cmd->redirection, box->files[i], 1);
            if (box->input_file)
            {
                int Getfd_input__ = open(box->input_file, O_RDONLY);
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
                if (dup2(Getfd_output__, 1) == -1)
                {
                    perror("dup2 output failed");
                    exit(1);
                }
                close(Getfd_output__);
            }
            else if (cmd->next)
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
        if (cmd->next)
        {
            close(fd[1]);
            prev_fd = fd[0];
        }
        i++;
        j++;
        cmd = cmd->next;
    }
    j = 0;
    while (j < the_size && box->pid[j] != -1)
    {
        while (waitpid(box->pid[j], &status, 0) > 0);
        if (WIFSIGNALED(status))
        {
            write(0, "\n", 1);
            box->exit_val = WTERMSIG(status) + 128;
        }
        else
            box->exit_val = WEXITSTATUS(status);
        j++;
    }
    return box->exit_val;
}
