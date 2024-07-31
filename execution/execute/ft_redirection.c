/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/30 18:17:59 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	ex___2(char *file)
// {
// 	int	fd;

// 	fd = open(file, O_RDONLY, 0666);
// 	if (fd == -1)
// 	{
// 		perror(file);
// 		exit(1);
// 	}
// }

// void	ex___3(char *file)
// {
// 	int	fd;

// 	fd = open(file, O_WRONLY | O_CREAT, 0666);
// 	if (fd == -1)
// 	{
// 		perror(file);
// 		exit(1);
// 	}
// }

// int ft_redirection(t_box *box, t_redirection *redirection, char* file)
// {
// 	int flag_input;
// 	int flag_output;

// 	flag_input = 1;
// 	flag_output = 1;

// 	int i = 0;
// 	while (redirection)
// 	{
// 		if(redirection->flag == 2 && flag_input)
// 		{
// 			box->input_file = redirection->str;
// 			// if(ft_strncmp(file, "N", -1) != 0)
// 				ex___2(box->input_file);
// 		}
// 		else if(redirection->flag == 3 && flag_output)
// 		{
// 			box->output_file = redirection->str;
// 			ex___3(box->output_file);
// 		}
// 		else if(redirection->flag == 4)
// 		{
// 			// i++;
// 			// if(ft_strncmp(file, "N", -1) != 0)
// 			// {
// 				box->input_file = file;
// 				flag_input = 0;
// 			// }
// 		}
// 		else if(redirection->flag == 5)
// 		{
// 			box->output_file = redirection->str;
// 			flag_output = 0;
// 			box->append = 400;
// 		}
// 		redirection = redirection->next;
// 	}
// 	return i;
// }


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
    // int flag_input = 1;
    // int flag_output = 1;

	int i = 0;
    while (redirection)
    {
        if(redirection->flag == 2)
        // && flag_input)
        {
			box->input_file = redirection->str;
			if(ft_strncmp(file, "N", -1) != 0)
				ex___2(box->input_file);
        }
        else if(redirection->flag == 3)
        //  && flag_output)
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
				// flag_input = 0;
			}
        }
        else if(redirection->flag == 5)
        {
            box->output_file = redirection->str;
            // flag_output = 0;
            box->append = 400;
        }
        redirection = redirection->next;
    }
    return 0;
}