/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 20:26:34 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    open_all_files(t_box *box)
{
   int pid;

   pid = fork();
   if(pid == -1)
   {
        perror("error");
        exit(0);
   }
   else if(pid == 0)
   {
        // int fd;
    
        while (box->node->command)
        {
            while (box->node->command->redirection)
            {
                // fd = open(box->node->command->redirection->str, O_RDONLY, 0666);
                // if(fd == -1)
                // {
                //     perror(box->node->command->redirection->str);
                //     exit(0);
                // }
                printf("%s\n", box->node->command->redirection->str);
                box->node->command->redirection = box->node->command->redirection->next;
            }
            box->node->command =  box->node->command->next;
        }
        exit(0);
   }
   while (wait(NULL) > 0);
}
