/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testPipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:37:37 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/08 23:38:19 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t cpid;
    char buf;
    const char *msg = "Hello, IPC!\n";

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    // Child process
        close(pipefd[1]);    // Close the write end of the pipe

        printf("Child: Reading from pipe...\n");
        while (read(pipefd[0], &buf, 1) > 0) {
            putchar(buf);
        }
        putchar('\n');
        close(pipefd[0]);
        exit(EXIT_SUCCESS);

    } else {            // Parent process
        close(pipefd[0]);    // Close the read end of the pipe

        printf("Parent: Writing to pipe...\n");
        write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]);
        wait(NULL);    // Wait for the child process to finish
        exit(EXIT_SUCCESS);
    }
}
