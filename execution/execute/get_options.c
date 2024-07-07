/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/07 00:50:38 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void    get_options(char **options)
{
    // int i;

    // i = 0;
    // while (options[i])
    // {
    //     printf("options:     %s\n", options[i]);
    //     i++;
    // }
    // char *args[1024];

    // // args[0] = "-l";
    // if(execve(options[0], args, NULL) == -1)
    // {
    //     printf("ERROR\n");
    // }

    //     if (argc < 2) {
    //     fprintf(stderr, "Usage: %s <command>\n", argv[0]);
    //     exit(EXIT_FAILURE);
    // }

    char *cmd = strdup(options[0]);
    char *args[1024];
    char *envp[] = { NULL }; // environment variables

    parse_command(cmd, args);

    char path[256];
    strcpy(path, "/bin/");
    strcat(path, args[0]);

    if (execve(path, args, envp) == -1) {
        perror("execve");
        free(cmd);
        exit(EXIT_FAILURE);
    }
    free(cmd);
    return ;
}
