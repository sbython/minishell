/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/01 15:43:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void more_then___(t_box *box)
{
    int fd[2];
    int prev_fd = -1;
    char **files;
    int i = 0;
    int j = 0;
    int status = 0;
    files = run_all_heardocs(box);
    box->pid = malloc(sizeee(box) * sizeof(int *));
    box->input_file = NULL;
    box->output_file = NULL;
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
        box->pid[j] = fork();
        if (box->pid[j] == -1)
        {
            perror("fork failed");
            exit(1);
        }
        else if (box->pid[j] == 0)
        {
            ft_redirection(box, box->node->command->redirection, files[i], 1);
            if (box->input_file)
            {
                put_input_file(box);
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
                put_output_file(box);
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
        j++;
        box->node->command = box->node->command->next;
    }
    j = 0;
    while (waitpid(box->pid[j++], &status, 0) > 0);
    // box->exit_val = WEXITSTATUS(status);
}
