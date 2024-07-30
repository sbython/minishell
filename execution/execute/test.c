/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/30 16:24:21 by zibnoukh         ###   ########.fr       */
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
    int flag_input;
	int flag_output;

	flag_input = 1;
	flag_output = 1;

	while (redirection)
	{
		if(redirection->flag == 2)
		{
			box->input_file = redirection->str;
			// if(ft_strncmp(file, "N", -1) != 0)
				// ex___2(box->input_file);
		}
		else if(redirection->flag == 3)
		{
			box->output_file = redirection->str;
			ex___33(box->output_file);
		}
		// else if(redirection->flag == 4)
		// {
		// 	i++;
		// 	if(ft_strncmp(file, "N", -1) != 0)
		// 	{
		// 		box->input_file = file;
		// 		flag_input = 0;
		// 	}
		// }
		else if(redirection->flag == 5)
		{
			box->output_file = redirection->str;
			flag_output = 0;
			box->append = 400;
		}
		redirection = redirection->next;
	}
	// return i;
}

void f(t_box *box)
{
    int        fd[2];
    int        prev_fd;
    int        pid;
    char **r;
    char *full_path;
    r = get_path__(box->env);
    box->input_file = NULL;
    box->output_file = NULL;
    prev_fd = -1;
    while (box->node->command)
    {
        if (box->node->command->next)
        {
            if (pipe(fd) == -1)
            {
                perror("pipe failed");
                exit(1);
            }
        }
        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            get_input_output(box, box->node->command->redirection);
            printf("input_file: %s\n", box->input_file);
            printf("output_file: %s\n", box->output_file);
        //     // open_files(box->node->command->redirection);
            int Getfd_input__;
            if (box->input_file)
            {
                Getfd_input__ = open(box->input_file, O_RDONLY);
                if (dup2(Getfd_input__, 0) == -1)
                {
                    perror("dup2 input failed");
                    exit(1);
                }
                close(Getfd_input__);
            }
            if (prev_fd != -1)
            {
                if (dup2(prev_fd, 0) == -1)
                {
                    perror("dup2 prev_fd failed");
                    exit(1);
                }
                close(prev_fd);
            }
            int Getfd_output__;
            if (box->output_file)
            {
                if (box->append)
                    Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
                else
                    Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
                if (Getfd_output__ == -1)
                {
                    perror(box->output_file);
                    exit(1);
                }
                if (dup2(Getfd_output__, 1) == -1)
                {
                    perror("dup2 output failed");
                    exit(1);
                }
                close(Getfd_output__);
            }
            if (box->node->command->next)
            {
                if (dup2(fd[1], 1) == -1)
                {
                    perror("dup2 fd[1] failed");
                    exit(1);
                }
                close(fd[1]);
            }
            full_path = fully(r, box->node->command->options[0]);
            if (!full_path)
            {
                printf("Command '%s' not found\n", box->node->command->options[0]);
                exit(0);
            }
            if (execve(full_path, box->node->command->options, box->full_env) == -1)
            {
                perror("execve failed");
                exit(1);
            }
        }
        if (prev_fd != -1)
            close(prev_fd);
        if (box->node->command->next)
        {
            close(fd[1]);
            prev_fd = fd[0];
        }
        box->node->command = box->node->command->next;
    }
    while (wait(NULL) > 0)
        ;
}
