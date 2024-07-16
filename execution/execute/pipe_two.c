/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/16 15:59:05 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void    execute_command(char *cmd, int input_fd, int output_fd)
// {
//     if (input_fd != 0)
//     { 
//         dup2(input_fd, 0);
//     }
//     if (output_fd != 1)
//     { 
//         dup2(output_fd, 1);
//     }

//     char *args[3];
//     char *command_path = ft_strjoin("/usr/bin/", cmd);
//     args[0] = command_path;
//     args[1] = NULL;

//     char *env[] = { NULL };

//     if(execve(command_path, args, env) == -1)
//     {
//         perror("execve failed");
//     }
// }

// void    pipe_two(t_box *box, char *prev, char *next)
// {
//     (void)box;
//     int pipe_fd[2];
//     if (pipe(pipe_fd) == -1)
//     {
//         perror("pipe failed");
//     }

//     pid_t pid1 = fork();
//     if (pid1 == -1)
//     {
//         perror("fork failed");
//     }

//     if (pid1 == 0)
//     { 
//         execute_command(prev, 0, pipe_fd[1]);
//     }

//     pid_t pid2 = fork();
//     if (pid2 == -1)
//     {
//         perror("fork failed");
//     }

//     if (pid2 == 0) 
//     { 
//         execute_command(next, pipe_fd[0], 1);
//     }

//     return ;
// }

void    execute_command(char *cmd, int input_fd, int output_fd)
{
    if (input_fd != 0)
    { 
        dup2(input_fd, 0);
    }
    if (output_fd != 1)
    { 
        dup2(output_fd, 1);
    }

    char *args[3];
    char *command_path = ft_strjoin("/usr/bin/", cmd);
    args[0] = command_path;
    args[1] = NULL;

    char *env[] = { NULL };

    if(execve(command_path, args, env) == -1)
    {
        perror("execve failed");
    }
}

void pipe_three(t_box *box, char *cmd1, char *cmd2, char *cmd3) 
{
    (void)box;
    int pipe_fd[4];
    
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe failed");
        exit(1);
    }

    pid_t pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid1 == 0)
    { 
        close(pipe_fd[0]);
        close(pipe_fd[2]);
        execute_command(cmd1, 0, pipe_fd[1]);
        // execute_c_options(box);
    }

    pid_t pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid2 == 0)
    { 
        close(pipe_fd[1]);
        close(pipe_fd[3]);
        execute_command(cmd2, pipe_fd[0], pipe_fd[2]);
    }

    pid_t pid3 = fork();
    if (pid3 == -1)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid3 == 0)
    { 
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execute_command(cmd3, pipe_fd[2], 1);
    }

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    close(pipe_fd[2]);
    close(pipe_fd[3]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
}
