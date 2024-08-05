/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/05 14:10:52 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ex___2(char *file, int move)
{
    int fd = open(file, O_RDONLY, 0666);
    if (fd == -1)
    {
        perror(file);
        if(move)
             exit(1);
    }
    close(fd);
}

void ex___3(char *file)
{
    int fd = open(file, O_WRONLY | O_CREAT, 0666);
    if (fd == -1)
    {
        perror(file);
        exit(1);
    }
    close(fd);
}

void ft_redirection(t_command *cmd, t_redirection *redirection, char* file, int move)
{
    char *out_put = NULL;
    char *in_put = NULL;
    while (redirection)
    {
        if (redirection->flag == 2)
        {
            in_put = redirection->str;
            ex___2(in_put, move);
        }
        else if (redirection->flag == 3)
        {
            out_put = redirection->str;
            ex___3(out_put);
        }
        else if (redirection->flag == 4)
        {
            in_put = file;
        }
        else if (redirection->flag == 5)
        {
            out_put = redirection->str;
            cmd->append = 400;
            ex___3(out_put);
        }
        redirection = redirection->next;
    }
    cmd->input_file = in_put;
    cmd->output_file = out_put;
}
