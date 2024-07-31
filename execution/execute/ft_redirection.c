/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/31 19:08:27 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ex___2(char *file)
{
    int fd = open(file, O_RDONLY, 0666);
    if (fd == -1)
    {
        perror(file);
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

int ft_redirection(t_box *box, t_redirection *redirection, char* file)
{
	int i = 0;
    while (redirection)
    {
        if(redirection->flag == 2)
        {
			box->input_file = redirection->str;
			ex___2(box->input_file);
        }
        else if(redirection->flag == 3)
        {
            box->output_file = redirection->str;
            ex___3(box->output_file);
        }
        else if(redirection->flag == 4)
        {
			i++;
			if(ft_strncmp(file, "N", -1) != 0)
			{
				box->input_file = file;
			}
        }
        else if(redirection->flag == 5)
        {
            box->output_file = redirection->str;
            box->append = 400;
        }
        redirection = redirection->next;
    }
    return 0;
}
