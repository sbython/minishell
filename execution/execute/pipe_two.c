/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/10 01:39:11 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    execute_command()
{
    
}

void    pipe_two(char *prev, char *next)
{
    int pipe_fd[2];
    if(pipe(pipe_fd) == -1)
        perror("pipe failed");
    
    
    pid_t pid1 = fork();
    if(pid1 == -1)
    {
        perror("fork 1 failed");
    }

    if(pid1 == 0)
    {
        execute_command(prev, next);
    }

    pid_t pid2 = fork();
    if(pid2 == -1)
    {
        perror("fork 2 failed");
    }

    if(pid2 == 0)
    {
        execute_command(prev, next);
    }
    
    printf("prev: %s\n", prev);
    printf("next: %s\n", next);
}
