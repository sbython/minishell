/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/01 14:56:06 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ex___22(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
	{
		perror(file);
		exit(1);
	}
}

void	ex___33(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		perror(file);
		exit(1);
	}
}

void get_input_output(t_box *box, t_redirection *redirection)
{
    (void)box;
    char *out_put = NULL;
    char *in_put = NULL;
    while (redirection)
    {
        // printf("str:   %s  ", redirection->str);
        // printf("flag:  %d\n", redirection->flag);
        if(redirection->flag == 2)
        {
            if(redirection->str)
                in_put = redirection->str;
            else
                in_put = NULL;
        }
        redirection = redirection->next;
    }

    box->input_file = in_put;
    box->output_file = out_put;
    printf("\n");
}

void f(t_box *box)
{
    box->input_file = NULL;
    box->output_file = NULL;
    while (box->node->command)
    {
        get_input_output(box, box->node->command->redirection);
        printf("input_file: %s\n", box->input_file);
        printf("output_file: %s\n", box->output_file);
        box->node->command = box->node->command->next;
    }
    // while (wait(NULL) > 0)
    //     ;
}
