/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:32:48 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/14 00:35:34 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    (void)argv

    // const char *delimiter = argv[1];
    // size_t delimiter_len = strlen(delimiter);
    // char buffer[BUFFER_SIZE];
    // char *input = NULL;
    // size_t input_size = 0;
    // size_t buffer_index = 0;
    // int delimiter_match = 0;

    // while (1) {
    //     // printf("< ");
    //     // if (write(STDOUT_FILENO, NULL, 0) == -1) {
    //     //     perror("Error flushing stdout");
    //     //     return 1;
    //     // }

    //     while (1) {
    //         ssize_t bytes_read = read(STDIN_FILENO, buffer + buffer_index, 1);
    //         if (bytes_read <= 0) {
    //             break;
    //         }

    //         if (buffer[buffer_index] == delimiter[delimiter_match]) {
    //             delimiter_match++;
    //             if (delimiter_match == delimiter_len) {
    //                 break;
    //             }
    //         } else {
    //             delimiter_match = 0;
    //         }

    //         buffer_index++;
    //         if (buffer_index == BUFFER_SIZE) {
    //             char *new_input = realloc(input, input_size + buffer_index + 1);
    //             if (!new_input) {
    //                 perror("Failed to allocate memory");
    //                 free(input);
    //                 return 1;
    //             }
    //             input = new_input;
    //             memcpy(input + input_size, buffer, buffer_index);
    //             input_size += buffer_index;
    //             buffer_index = 0;
    //         }

    //         if (buffer[buffer_index - 1] == '\n') {
    //             break;
    //         }
    //     }

    //     if (delimiter_match == delimiter_len) {
    //         break;
    //     }

    //     if (buffer_index > 0) {
    //         char *new_input = realloc(input, input_size + buffer_index + 1);
    //         if (!new_input) {
    //             perror("Failed to allocate memory");
    //             free(input);
    //             return 1;
    //         }
    //         input = new_input;
    //         memcpy(input + input_size, buffer, buffer_index);
    //         input_size += buffer_index;
    //         buffer_index = 0;
    //     }
    // }

    // if (buffer_index > 0) {
    //     char *new_input = realloc(input, input_size + buffer_index + 1);
    //     if (!new_input) {
    //         perror("Failed to allocate memory");
    //         free(input);
    //         return 1;
    //     }
    //     input = new_input;
    //     memcpy(input + input_size, buffer, buffer_index);
    //     input_size += buffer_index;
    // }

    // input[input_size] = '\0';

    // int pipe_fds[2];
    // if (pipe(pipe_fds) == -1) {
    //     perror("Failed to create pipe");
    //     free(input);
    //     return 1;
    // }

    // pid_t pid = fork();
    // if (pid == 0) {
        // close(pipe_fds[1]); 
        // dup2(pipe_fds[0], STDIN_FILENO);
        // close(pipe_fds[0]);

    //     char *args[] = { "ls", NULL };
    //     char *envp[] = { NULL };
    //     execve("/bin/ls", args, envp);
    //     perror("Failed to execute ls");
    //     return 1;
    // } else if (pid > 0) {
        // close(pipe_fds[0]);
        // write(pipe_fds[1], input, input_size); 
        // close(pipe_fds[1]);

    //     int status;
    //     waitpid(pid, &status, 0);

        // printf("\nContent of %s:\n%s", delimiter, input);
        // free(input);
    // } else {
    //     perror("Failed to fork");
    //     free(input);
    //     return 1;
    // }

    return 0;
}
