/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/17 09:20:01 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(t_box*box, char *cmd, int input_fd, int output_fd)
{
    (void)cmd;
    (void)box;
    if (input_fd != 0) {
        dup2(input_fd, 0);
        close(input_fd);
    }
    if (output_fd != 1) {
        dup2(output_fd, 1);
        close(output_fd);
    }

    // char command_path[1024];
    // snprintf(command_path, sizeof(command_path), "/bin/%s", cmd);

    // char *args[] = {command_path, NULL};
    // char *env[] = { NULL };
    char *command_path = ft_strjoin("/bin/", cmd);

    // char** r = get_path(box->env);
    // char *env[] = { NULL };  
    // char *full_path = get_full_path__(box, r);
    char *args[] = {command_path, NULL};
    // if(execve(command_path, args, box->full_env) == -1)
    if (execvp(command_path, args) == -1) 
    {
        perror("execve failed");
        exit(1);
    }
    {
        perror("EXIT");
        exit(0);
    }
}

void pipe_commands(t_box*box, char **commands, int num_commands) 
{
    (void)num_commands;
    (void)box;
    // printf("%s\n", commands[0]);
    // int i = 0;
    // while (commands[i])
    // {
    //     printf("commands: %s", commands[i]);
    //     i++;
    // }
    // printf("\n");

    int i;
    int pipe_fd[2 * (num_commands - 1)];
    pid_t pid;

    i = 0;
    while ( i < num_commands - 1) 
    {
        if (pipe(pipe_fd + i * 2) == -1) 
        {
            perror("pipe failed");
            exit(1);
        }
        i++;
    }

    int command_count = 0;
    while (command_count < num_commands)
    {
        pid = fork();
        if (pid == -1) 
        {
            perror("fork failed");
            exit(1);
        }
        if (pid == 0)
        { 
            if (command_count > 0) 
            {
                dup2(pipe_fd[(command_count - 1) * 2], 0);
            }
            if (command_count < num_commands - 1) 
            {
                dup2(pipe_fd[command_count * 2 + 1], 1);
            }

            i = 0;
            while ( i < 2 * (num_commands - 1)) 
            {
                close(pipe_fd[i]);
                i++;
            }

            execute_command(box,commands[command_count], 0, 1);
        }
        command_count++;
    }

    i = 0;
    while ( i < 2 * (num_commands - 1)) 
    {
        close(pipe_fd[i]);
        i++;
    }

    i = 0;
    while ( i < num_commands) 
    {
        wait(NULL);
        i++;
    }
}
