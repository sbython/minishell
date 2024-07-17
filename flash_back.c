/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flash_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 06:10:32 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/17 06:57:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct {
    // Define your struct fields as needed
} t_box;

void execute_command(char *cmd, int input_fd, int output_fd) {
    if (input_fd != 0) {
        dup2(input_fd, 0);
        close(input_fd);
    }
    if (output_fd != 1) {
        dup2(output_fd, 1);
        close(output_fd);
    }

    char command_path[1024];
    snprintf(command_path, sizeof(command_path), "/bin/%s", cmd);

    char *args[] = {command_path, NULL};
    char *env[] = { NULL };

    if (execve(command_path, args, env) == -1) {
        perror("execve failed");
        exit(1);
    }
}

void pipe_commands(t_box *box, char **commands, int num_commands) {
    (void)box;
    int i;
    int pipe_fd[2 * (num_commands - 1)];
    pid_t pid;

    // Create pipes
    for (i = 0; i < num_commands - 1; i++) {
        if (pipe(pipe_fd + i * 2) == -1) {
            perror("pipe failed");
            exit(1);
        }
    }

    int command_count = 0;
    while (command_count < num_commands) {
        pid = fork();
        if (pid == -1) {
            perror("fork failed");
            exit(1);
        }
        if (pid == 0) { // Child process
            if (command_count > 0) {
                // Not the first command, get input from previous pipe
                dup2(pipe_fd[(command_count - 1) * 2], 0);
            }
            if (command_count < num_commands - 1) {
                // Not the last command, output to next pipe
                dup2(pipe_fd[command_count * 2 + 1], 1);
            }

            // Close all pipe ends
            for (i = 0; i < 2 * (num_commands - 1); i++) {
                close(pipe_fd[i]);
            }

            execute_command(commands[command_count], 0, 1);
        }
        command_count++;
    }

    // Close all pipe ends in parent
    for (i = 0; i < 2 * (num_commands - 1); i++) {
        close(pipe_fd[i]);
    }

    // Wait for all child processes to finish
    for (i = 0; i < num_commands; i++) {
        wait(NULL);
    }
}

int main() {
    t_box box; // Example struct, adjust as needed

    // Example usage with "ls | echo | pwd"
    char *commands[] = {"ls", "echo", "pwd", "free"};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    pipe_commands(&box, commands, num_commands);

    return 0;
}
