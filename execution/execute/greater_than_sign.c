/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/13 00:42:29 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void ex_command(char *prev, char *next)
// {
//     (void)prev;
//     // int fd;

//     // fd = open(next, O_APPEND, O_RDONLY); 
//     printf("next of >: %s\n", next);  
// }

void    greater_than_sign(t_box *box, t_com *l_com)
{
    pid_t pid;
    int status;
    int fd;

    fd = open(l_com->next->com, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("open");
        exit(0);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(0);
    } 
    else if (pid == 0)
    {
        char *path = "/bin/";
        char *full_path = ft_strjoin(path, box->node->command->options[0]);
        if (dup2(fd, 1) == -1)
        {
            perror("dup2");
            exit(0);
        }
        close(fd);

        if (execve(full_path, box->node->command->options, NULL) == -1)
        {
            perror("execve");
            exit(0);
        }
    } 
    else 
    {
        close(fd);
        if (waitpid(pid, &status, 0) == -1) 
        {
            perror("waitpid");
            exit(0);
        }
    }
}
