/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/03 15:56:28 by zibnoukh         ###   ########.fr       */
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

void ft_redirection(t_box *box, t_redirection *redirection, char* file, int move)
{
    char *out_put = NULL;
    char *in_put = NULL;
    while (redirection)
    {
        if(redirection->flag == 2)
        {
            if(redirection->str)
            {
                in_put = redirection->str;
                ex___2(in_put, move);
            }
            else
                in_put = NULL;
        }
        else if(redirection->flag == 3)
        {
            if(redirection->str)
            {
                out_put = redirection->str;
                ex___3(out_put);
            }
            else
                out_put = NULL;
        }
        else if(redirection->flag == 4)
        {
            if(redirection->str)
                in_put = file;
            else
                in_put = NULL;
        }
        else if(redirection->flag == 5)
        {
            if(redirection->str)
            {
                out_put = redirection->str;
                box->append = 400;
                ex___3(out_put);
            }
            else
                out_put = NULL;
        }
        redirection = redirection->next;
    }
    box->input_file = in_put;
    box->output_file = out_put;
}
