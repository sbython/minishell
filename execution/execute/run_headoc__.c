/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_headoc__.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/23 09:01:47 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char* run___heardoc(char *file)
{
    char*cpy_str_val = ft_strdup(file);
    char*new_file = random_file(cpy_str_val);
    char *promptt = "> ";
    int fd;
    char *line;
    fd = open(new_file, O_WRONLY | O_CREAT, 0666);
    while ((line = readline(promptt)) != NULL)
    {
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        if(ft_strncmp(line, file, ft_strlen(file)) == 0 
        && ft_strlen(file) == ft_strlen(line))
        {
            break;
        }
    }
    return new_file;
}

void    run_headoc__(t_box *box)
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
        while (box->node->command)
        {
            while (box->node->command->redirection)
            {
                if(box->node->command->redirection->flag == 4)
                {
                   box->speinput_file = run___heardoc(box->node->command->redirection->str);
                }
                box->node->command->redirection = box->node->command->redirection->next;
            }
            box->node->command =  box->node->command->next;
        }
        exit(0);
   }
   while (wait(NULL) > 0);
}
