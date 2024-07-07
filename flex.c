/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:04 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/07 23:39:57 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void parse_command(char *cmd, char **args) {
    char *token;
    int i = 0;

    token = strtok(cmd, " ");
    while (token != NULL && i < 1024 - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

void get_options(char **options) {
    char *cmd = strdup(options[0]);
    char *args[1024];
    char *envp[] = { NULL }; // environment variables
    pid_t pid;
    int status;

    parse_command(cmd, args);

    pid = fork();
    if (pid == -1) {
        perror("fork");
        free(cmd);
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        char path[256];
        strcpy(path, "/bin/");
        strcat(path, args[0]);

        if (execve(path, args, envp) == -1) {
            perror("execve");
            free(cmd);
            exit(EXIT_FAILURE);
        }
    } else { // Parent process
        do {
            pid_t wpid = waitpid(pid, &status, WUNTRACED);
            if (wpid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(cmd);
    return;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    get_options(&argv[1]);

    return 0;
}
