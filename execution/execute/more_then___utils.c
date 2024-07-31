/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/31 19:36:22 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void put_output_file(t_box *box)
{
    int Getfd_output__;
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

void put_input_file(t_box *box)
{
    int Getfd_input__ = open(box->input_file, O_RDONLY);
    if (Getfd_input__ == -1)
    {
        perror(box->input_file);
        exit(1);
    }
    if (dup2(Getfd_input__, 0) == -1)
    {
        perror("dup2 input failed");
        exit(1);
    }
    close(Getfd_input__);
}

void use_pipe(int fd[2])
{
    if (pipe(fd) == -1)
    {
        perror("pipe failed");
        exit(1);
    }
}

int  put_builtins(char *ptr)
{
	if (ft_strncmp(ptr, "cd", -1) == 0)
        return 1;
	else if (ft_strncmp(ptr, "echo", -1) == 0)
        return 1;
	else if (ft_strncmp(ptr, "pwd", -1) == 0)
	    return 1;
	else if (ft_strncmp(ptr, "exit", -1) == 0)
		return 1;
	else if (ft_strncmp(ptr, "export", -1) == 0)
		return 1;
	else if (ft_strncmp(ptr, "env", -1) == 0)
		return 1;
	else if (ft_strncmp(ptr, "unset", -1) == 0)
		return 1;
	return (0);
}

void exe_cvee(t_box *box)
{
    char **r;
    char *full_path;

    if(put_builtins(box->node->command->options[0]))
    {
        builtins(box->node->command->options, box);
        exit(0);
    }
    else
    {
        r = get_path__(box->env);
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
}
