/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 20:57:01 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute(t_box *box)
{
    run_headoc__(box);
    // open_all_files(box);
    char** r = get_path__(box->env);
    while (box->node->command)
    {
        int pid;

        pid = fork();
        if(pid == -1)
        {
            perror("failed");
            exit(0);
        }
        else if(pid == 0)
        {
            ft_redirection(box, box->node->command->redirection);
            printf("box->input_file: %s\n", box->input_file);
            printf("box->output_file: %s\n", box->output_file);
            
            int Getfd_input__ = open(box->input_file, O_RDONLY, 0666);
            int Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
            if(Getfd_input__)
            {
                if(dup2(Getfd_input__, 0) == -1)
                {
                    perror("dup 1 faled");
                    exit(0);
                }
            }

            if(Getfd_output__)
            {
                if(dup2(Getfd_output__, 1) == -1)
                {
                    perror("dup 2 faled");
                    exit(0);
                }
            }


            char *full_path = fully(r, box->node->command->options[0]);
            if((execve(full_path, box->node->command->options, box->full_env) == -1))
            {
                ft_putstr_fd("file not found\n", 2);
                exit(0);
            }
        }
        box->node->command = box->node->command->next;
    }
    while (wait(NULL) > 0);
}
