/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_then___utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/05 13:36:17 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void put_output_file(t_box *box)
{
    (void)box;
    // int Getfd_output__;
    // if (box->append)
    //     Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
    // else
    //     Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    // if (dup2(Getfd_output__, 1) == -1)
    // {
    //     perror("dup2 output failed");
    //     exit(1);
    // }
    // close(Getfd_output__);
}

void put_input_file(t_box *box)
{
    (void)box;
    // int Getfd_input__ = open(box->input_file, O_RDONLY);
    // if (dup2(Getfd_input__, 0) == -1)
    // {
    //     perror("dup2 input failed");
    //     exit(1);
    // }
    // close(Getfd_input__);
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

void exe_cvee(t_box*box, t_command *cmd)
{
    char **r;
    char *full_path;

    if(put_builtins(cmd->options[0]))
    {
        builtins(cmd->options, box, 0);
        exit(0);
    }
    else
    {
        r = get_path__(box->env);
        full_path = fully(r, cmd->options[0]);
        if (!full_path || (ft_strncmp(cmd->options[0], "", -1) == 0))
        {
            ft_putstr_fd("Command '", 2);
            ft_putstr_fd(cmd->options[0], 2);
            ft_putstr_fd("' not found\n", 2);
            exit(127);
        }
        if (execve(full_path, cmd->options, box->full_env) == -1)
        {
            perror("execve failed");
            exit(1);
        }
    }
}
