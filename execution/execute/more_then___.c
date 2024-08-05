/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/05 13:42:12 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int more_then___(t_box *box)
{
    int fd[2];
    int prev_fd = -1;
    int pid = 0;
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
        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            if (prev_fd != -1)
            {
                if (dup2(prev_fd, 0) == -1)
                {
                    perror("dup2 prev_fd failed");
                    exit(1);
                }
                close(prev_fd);
            }
            if (cmd->next)
            {
                if (dup2(fd[1], 1) == -1)
                {
                    perror("dup2 fd[1] failed");
                    exit(1);
                }
                close(fd[1]);
            }
            exe_cvee(box, cmd);
            exit(0);
        }
        if (prev_fd != -1)
            close(prev_fd);
        if (cmd->next)
        {
            close(fd[1]);
            prev_fd = fd[0];
        }
        cmd = cmd->next;
    }
    while (wait(NULL) > 0){};
    return 0;
}
