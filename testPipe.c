/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testPipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:37:37 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/10 01:38:15 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(const char *cmd, int input_fd, int output_fd)
{
    if (input_fd != 0) { 
        dup2(input_fd, 0);
        close(input_fd);
    }
    if (output_fd != 1) { 
        dup2(output_fd, 1);
        close(output_fd);
    }

    char *args[3];
    char command_path[256];

    snprintf(command_path, sizeof(command_path), "/bin/%s", cmd);
    args[0] = command_path;
    args[1] = NULL;

    char *env[] = { NULL };

    execve(command_path, args, env);
    perror("execve failed");
    exit(1);
}

int main(int argc, char *argv[])
{
    int pipe_fd[2];
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
        // close(pipe_fd[0]); 
        execute_command(argv[1], 0, pipe_fd[1]);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) { 
        // close(pipe_fd[1]);
        execute_command(argv[2], pipe_fd[0], 1);
    }

    // close(pipe_fd[0]);
    // close(pipe_fd[1]);

    // waitpid(pid1, NULL, 0);
    // waitpid(pid2, NULL, 0);

    return 0;
}
