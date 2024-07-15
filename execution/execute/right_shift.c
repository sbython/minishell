/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:58:44 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/15 18:05:52 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    right_shift(t_box *box, char *file)
{
    (void)box;
    char **r = get_path(box->env);
    int fd;

    fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0666);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(0);
    }
    else if (pid == 0)
    {
        if (dup2(fd, 0) == -1)
        {
            perror("dup2");
            exit(0);
        }

        if (dup2(fd, 1) == -1)
        {
            perror("dup2");
            exit(0);
        }

        close(fd);

        char *full_path = get_full_path__(box, r);
        if (execve(full_path, box->node->command->options, box->full_env) == -1)
        {
            perror("execve");
            exit(0);
        }
        exit(0);
    }
    else
    {
        close(fd);

        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            exit(0);
        }
    }
}
