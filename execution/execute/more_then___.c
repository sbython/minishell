/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/30 10:16:06 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void more_then___(t_box *box)
{
    char **files;
    int fd[2];
    int prev_fd;
    int pid;
    prev_fd = -1;
    int i;
    files = run_all_heardocs(box);
    i = 0;
    while (box->node->command && i <  n(files) + 1)
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
            put_input_file(box);
            if (prev_fd != -1)
            {
                if (dup2(prev_fd, 0) == -1)
                {
                    perror("dup2 prev_fd failed");
                    exit(1);
                }
                close(prev_fd);
            }
            put_output_file(box);
            if (box->node->command->next)
            {
                if (dup2(fd[1], 1) == -1)
                {
                    perror("dup2 fd[1] failed");
                    exit(1);
                }
                close(fd[1]);
            }
            ex_execve(box);
        }
        if (prev_fd != -1)
            close(prev_fd);
        if (box->node->command->next)
        {
            close(fd[1]);
            prev_fd = fd[0];
        }
        box->node->command = box->node->command->next;
		i++;
    }
    while (wait(NULL) > 0)
        ;
}
