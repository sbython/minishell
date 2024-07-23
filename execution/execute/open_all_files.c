/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/23 09:45:00 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    open_all_files(t_redirection *red)
{
//    int pid;

//    pid = fork();
//    if(pid == -1)
//    {
//         perror("error");
//         exit(0);
//    }
//    else if(pid == 0)
//    {
        int fd;
    
            while (red)
            {
                if(red->flag == 2)
                {
                    fd = open(red->str, O_RDONLY, 0666);
                    if(fd == -1)
                    {
                        perror(red->str);
                        exit(0);
                    }
                }
                red = red->next;
            }
        // exit(0);
//    }
//    while (wait(NULL) > 0);
}
