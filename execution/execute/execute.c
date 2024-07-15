/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/15 18:03:54 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    length_opp(char **opp)
{
    int i;

    i = 0;
    while (opp[i])
        i++;
    return i;
}

void    execute(t_box *box)
{
    // char *command = "ls -al > file << cv < cd";

    // const char delim[] = " \t\n";
    // char *token;
    // char *saveptr;
    // char *commands[50];  

    // int i = 0;
    // token = strtok_r(command, delim, &saveptr);
    // while (token != NULL)
    // {
    //     commands[i++] = token;
    //     token = strtok_r(NULL, delim, &saveptr);
    // }
    // commands[i] = NULL; 

    // // int pipefd[2];

    // i = 0;
    // while (commands[i] != NULL)
    // {
    //     if (strcmp(commands[i], ">") == 0)
    //     {
    //         if (commands[i + 1] != NULL)
    //         {
    //             greater_than_sign(box, commands[i + 1]);
    //             i += 2;
    //         }
    //         else
    //         {
    //             fprintf(stderr, "Syntax error: Missing filename after `>`\n");
    //             exit(EXIT_FAILURE);
    //         }
    //     }
    //     else if (strcmp(commands[i], "<") == 0)
    //     {
    //         if (commands[i + 1] != NULL)
    //         {
    //             less_than_sign(box, commands[i + 1]);
    //             i += 2; 
    //         }
    //         else
    //         {
    //             fprintf(stderr, "Syntax error: Missing filename after `<`\n");
    //             exit(EXIT_FAILURE);
    //         }
    //     }
    //     else if (strcmp(commands[i], ">>") == 0)
    //     {
    //         if (commands[i + 1] != NULL)
    //         {
    //             int fd = open(commands[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0666);
    //             if (fd == -1)
    //             {
    //                 perror("open");
    //                 exit(EXIT_FAILURE);
    //             }
    //             right_shift(box, &fd);
    //             i += 2; 
    //         }
    //         else
    //         {
    //             fprintf(stderr, "Syntax error: Missing filename after `>>`\n");
    //             exit(EXIT_FAILURE);
    //         }
    //     }
    //     else if (strcmp(commands[i], "<<") == 0)
    //     {
    //         if (commands[i + 1] != NULL)
    //         {
    //             fprintf(stderr, "Syntax error: `<<` not supported in this context\n");
    //             exit(EXIT_FAILURE);
    //         }
    //         else
    //         {
    //             fprintf(stderr, "Syntax error: Missing delimiter after `<<`\n");
    //             exit(EXIT_FAILURE);
    //         }
    //     }
    //     else
    //     {
    //         execute_c_options(box);
    //         i++;
    //     }
    // }
    // int *pip_fd;
    
    // pip_fd = ft_calloc(2, sizeof(int));
    // pip_fd[1] = 1;
    // open_1(pip_fd, box->node->command->redirection);
    // right_shift(box, pip_fd);
    if(!box->node->command->redirection)
        execute_c_options(box);
    else
        redirection(box);
}
// (void)box;
