/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/05 14:23:31 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int more_then___(t_box *box)
{
    int fd[2];
    int prev_fd = -1;
    int pid = 0;
    t_command* cmd = box->node->command;
    int i = 0;
    int j = 0;
    cmd->files = NULL;
    if (run_all_heardocs(cmd, box))
        return (box->exit_val);
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
        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            handlesignal(2, box);
            ft_redirection(cmd, cmd->redirection, cmd->files[i], 1);
            if (cmd->input_file)
            {
                int Getfd_input__ = open(cmd->input_file, O_RDONLY);
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
            if (cmd->output_file)
            {
                int Getfd_output__;
                if (cmd->append)
                    Getfd_output__ = open(cmd->output_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
                else
                    Getfd_output__ = open(cmd->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
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
            exe_cvee(box, cmd);
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
    while (wait(NULL) > 0){};
    return 0;
}
