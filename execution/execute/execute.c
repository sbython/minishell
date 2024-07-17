/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/17 13:49:06 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void execute(t_box *box)
{
    (void)box;
    t_command *current_command = box->node->command;
    int pipe_fd[2];  
    
    int prev_pipe_read = -1;
    char** r = get_path__(box->env);
    
    while (current_command) 
    {
        if (pipe(pipe_fd) == -1) 
        {
            perror("error");
            exit(0);
        }
        
        pid_t pid = fork();
        if (pid == -1) 
        {
            perror("fork failed");
            exit(0);
        } 
        else if (pid == 0)
        { 
            if (prev_pipe_read != -1) 
            {
                dup2(prev_pipe_read, 0); 
                close(prev_pipe_read);  
            }
            
            if (current_command->next != NULL)
                dup2(pipe_fd[1], 1); 
            
            close(pipe_fd[0]);
            
            char *full_path = fully(r, current_command->options[0]);
            if(execve(full_path, current_command->options, box->full_env) == -1)
            {
                perror("EXIT");
                exit(0);
            }
            perror("execve failed");
            exit(0);
        } 
        else 
        { 
            if (prev_pipe_read != -1) 
                close(prev_pipe_read);  
            
            close(pipe_fd[1]);  
            prev_pipe_read = pipe_fd[0];
            
            current_command = current_command->next;
        }
    }
    close(prev_pipe_read);
    while (wait(NULL) > 0);
}
