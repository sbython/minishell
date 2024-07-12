/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_c_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/11 22:52:42 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    execute_c_options(t_box *box)
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
        char *f = ft_strjoin(path, box->node->command->options[0]);
        if(execve(f, box->node->command->options, NULL) == -1)
            perror("EXIT");
    }
    else
    {
        if (waitpid(pid, __stat_loc, 0) == -1) {
            perror("waitpid");
        }
    }
}
