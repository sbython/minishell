/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 09:11:22 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    get_options(char **options)
{
    // if(options)
    // {
        int i = 0;
        while (options[i])
        {
            printf("option: %s\n", options[i]);
            i++;
        }
    // }
    // else
        // printf("NULL");
    
    // pid_t pid;

    // pid = fork();
    // int *__stat_loc = NULL;
    // if (pid == -1) {
    //     perror("fork");
    // }
    // else if(pid == 0)
    // {
    //     char *path = "/bin/";
    //     char *f = ft_strjoin(path, options[0]);
    //     if(execve(f, options, NULL) == -1)
    //         perror("EXIT");
    // }
    // else
    // {
    //     if (waitpid(pid, __stat_loc, 0) == -1) {
    //         perror("waitpid");
    //     }
    // }
}
