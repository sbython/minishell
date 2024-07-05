/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:43:04 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/05 21:51:23 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ARGS 64

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

int main(int argc, char *argv[]) {

    char *cmd = strdup(argv[1]);
    char *args[MAX_ARGS];

    parse_command(cmd, args);

    if (execvp(args[0], args) == -1) {
        perror("execvp");
        free(cmd); 
        exit(EXIT_FAILURE);
    }

    free(cmd); 
    return 0;
}
