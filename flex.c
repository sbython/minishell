/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:04 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/07 00:44:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 1024
#define PATH_SIZE 256

void parse_command(char *cmd, char **args) {
    char *token;
    int i = 0;

    token = strtok(cmd, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *cmd = strdup(argv[1]);
    char *args[MAX_ARGS];
    char *envp[] = { NULL }; // environment variables

    parse_command(cmd, args);

    char path[PATH_SIZE];
    strcpy(path, "/bin/");
    strcat(path, args[0]);

    if (execve(path, args, envp) == -1) {
        perror("execve");
        free(cmd);
        exit(EXIT_FAILURE);
    }
    free(cmd);
    return 0;
}
