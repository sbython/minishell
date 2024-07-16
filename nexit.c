/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 06:54:47 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/16 13:22:44 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 4

// int main()
// {
    // char *commands[MAX_COMMANDS][4] = {
    //     {"/bin/pwd", NULL},
    //     {"/bin/cat", "-e", NULL},
    //     {"/bin/free", "-k",NULL},
    //     {"/bin/ls", "-al",NULL}
    // };
    // int num_commands = MAX_COMMANDS;
    // int pipes[MAX_COMMANDS - 1][2];
    // pid_t pid[MAX_COMMANDS];

    // int i = 0;
    // while ( i < num_commands - 1)
    // {
    //     if (pipe(pipes[i]) == -1)
    //     {
    //         perror("pipe");
    //         exit(0);
    //     }
    //     i++;
    // }

    // while (i < num_commands)
    // {
    //     pid[i] = fork();

    //     if (pid[i] == -1)
    //     {
    //         perror("fork");
    //         exit(0);
    //     }

    //     if (pid[i] == 0)
    //     {
    //         if (i > 0)
    //             dup2(pipes[i - 1][0], 0);

    //         if (i < num_commands - 1)
    //             dup2(pipes[i][1], 1);

    //         // printf("commands[i][0]: %s\n", commands[i][0]);
    //         // while (commands[i])
    //         // {
    //         //     printf("commands[i]: %s\n", commands[i]);
    //         //     i++;
    //         // }
            
    //         execve(commands[i][0], commands[i], NULL);
    //         // execve("/bin/ls", box[i], NULL);
    //         // box->n
    //         perror("execve");
    //         exit(0);
    //     }
    //     i++;
    // }

    // int j = 0;
    // while (j < num_commands - 1) 
    // {
    //     close(pipes[j][0]);
    //     close(pipes[j][1]);
    //     j++;
    // }

    // while (j < num_commands) 
    // {
    //     waitpid(pid[j], NULL, 0);
    //     j++;
    // }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *ft_strjoin(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        perror("malloc failed");
        exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void execute_command(char *cmd, int input_fd, int output_fd) {
    if (input_fd != 0) {
        dup2(input_fd, 0);
        close(input_fd);
    }
    if (output_fd != 1) {
        dup2(output_fd, 1);
        close(output_fd);
    }

    // Tokenize the command string to handle arguments
    char *args[100];
    char *token = strtok(cmd, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Search for the command in standard paths
    char *paths[] = { "/bin/", "/usr/bin/", NULL };
    char *command_path = NULL;

    for (i = 0; paths[i] != NULL; i++) {
        command_path = ft_strjoin(paths[i], args[0]);
        if (access(command_path, X_OK) == 0) {
            break;
        }
        free(command_path);
        command_path = NULL;
    }

    if (command_path == NULL) {
        perror("execve failed");
        exit(1);
    }

    if (execve(command_path, args, NULL) == -1) {
        perror("execve failed");
        exit(1);
    }
}

void pipe_multiple(char **commands, int num_commands) {
    int pipe_fd[2 * (num_commands - 1)];
    pid_t pids[num_commands];

    // Create all the necessary pipes
    for (int i = 0; i < num_commands - 1; i++) {
        if (pipe(pipe_fd + 2 * i) == -1) {
            perror("pipe failed");
            exit(1);
        }
    }

    for (int i = 0; i < num_commands; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            perror("fork failed");
            exit(1);
        }

        if (pids[i] == 0) {
            // Set up input and output file descriptors
            if (i != 0) {
                if (dup2(pipe_fd[2 * (i - 1)], 0) == -1) {
                    perror("dup2 failed");
                    exit(1);
                }
            }
            if (i != num_commands - 1) {
                if (dup2(pipe_fd[2 * i + 1], 1) == -1) {
                    perror("dup2 failed");
                    exit(1);
                }
            }

            // Close all pipe file descriptors
            for (int j = 0; j < 2 * (num_commands - 1); j++) {
                close(pipe_fd[j]);
            }

            // Execute the command
            execute_command(commands[i], 0, 1);
        }
    }

    // Close all pipe file descriptors in the parent process
    for (int i = 0; i < 2 * (num_commands - 1); i++) {
        close(pipe_fd[i]);
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_commands; i++) {
        waitpid(pids[i], NULL, 0);
    }
}

// Example usage
int main() {
    char *commands[] = { "ls", "grep .c", "wc -l" };
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    pipe_multiple(commands, num_commands);

    return 0;
}
