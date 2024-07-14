/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_c_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 13:22:50 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char *get_full_path__(t_box*box,  char **r)
{
    int i = 0;
    while(r[i] != NULL)
    {
        char *str = ft_strjoin(r[i], ft_strjoin("/", box->node->command->options[0]));
        if (access(str, X_OK) == 0)
            return (str);
        i++;
    }
    return (NULL);
}

void    execute_c_options(t_box *box)
{
    char** r = get_path(box->env);
    pid_t pid;

    pid = fork();
    int *__stat_loc = NULL;
    if (pid == -1) {
        perror("fork");
    }
    else if(pid == 0)
    {
        char *full_path = get_full_path__(box, r);
        if(execve(full_path, box->node->command->options, NULL) == -1)
            perror("EXIT");
    }
    else
    {
        if (waitpid(pid, __stat_loc, 0) == -1) {
            perror("waitpid");
        }
    }
}
