/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/08 00:23:57 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void parse_command(char *cmd, char **args) {
//     char *token;
//     int i = 0;

//     token = strtok(cmd, " ");
//     while (token != NULL && i < 1024 - 1) {
//         args[i++] = token;
//         token = strtok(NULL, " ");
//     }
//     args[i] = NULL;
// }

void    get_options(char **options)
{
    pid_t pid;

    pid = fork();
    int *__stat_loc = NULL;
    if (pid == -1) {
        perror("fork");
    }
    else if(pid == 0)
    {
        char *path = "/bin/";
        char *f = ft_strjoin(path, options[0]);
        if(execve(f, options, NULL) == -1)
            perror("EXOT");
        
    }
    else
    {
        if (waitpid(pid, __stat_loc, 0) == -1) {
            perror("waitpid");
        }
    }
}
