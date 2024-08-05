/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_heardocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/05 13:35:26 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	run_her(t_box* box ,char *file)
{
	char	*new_file;
	char	*cpy_str_val;
	cpy_str_val = ft_strdup(file);
	new_file = random_file(cpy_str_val);
	int status = 0;
	int j = 0;
	box->pid = malloc(sizeee(box) * sizeof(int *));
	box->pid[j] = fork();
	if(box->pid[j] == -1)
	{
		perror("fork failed");
        exit(1);
	}
	else if (box->pid[j] == 0)
	{
		handlesignal(4, box);
		int		fd;
		char	*line;
		fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		while ((line = readline("> ")) != NULL)
		{
			if (ft_strncmp(line, file, ft_strlen(file)) == 0
				&& ft_strlen(file) == ft_strlen(line))
			{
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		free(line);
		exit(0);
	}
	waitpid(box->pid[j], &status, 0);
	box->new_file_val = new_file;
	box->exit_val = 0;
	if (WIFSIGNALED(status))
    {
		write(0, "\n", 1);
        box->exit_val = 130;
    }
	if(!new_file)
		free(new_file);
	free(cpy_str_val);
	free(box->pid);
    return box->exit_val;
}

int run_all_heardocs(t_box *box) 
{
    int j = 0;
	int k = 0;
    t_command *tmp = box->node->command;
    char **r = (char **)malloc(sizeof(char *) * (how_her(box) + 1));
    if (!r) 
	{
        perror("malloc");
        return 0;
    }
    while (tmp) 
	{
		t_redirection *red_tmp = tmp->redirection;
		char *last_file = NULL;
		while (red_tmp) 
		{
			if (red_tmp->flag == 4) 
			{ 
				if (last_file) 
					free(last_file);
				if(run_her(box, red_tmp->str))
					return 1;
				last_file = box->new_file_val;
				if (!last_file) 
				{
					k = 0;
					while (k < j) 
					{
						free(r[k]);
						k++;
					}
					free(r);
					return 0;
				}
			}
			red_tmp = red_tmp->next;
		}
		if (last_file) 
			r[j++] = last_file;
		tmp = tmp->next;
    }
    r[j] = NULL;
	// box->files = r;
	free(r);
	return (0);
}
