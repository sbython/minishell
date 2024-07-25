/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/23 10:50:24 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_s(char *file)
{
	char	*cpy_str_val;
	char	*new_file;
	char	*promptt;
	int		fd;
	char	*line;

	cpy_str_val = ft_strdup(file);
	new_file = random_file(cpy_str_val);
	promptt = "> ";
	fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	while ((line = readline(promptt)) != NULL)
	{
		if (ft_strncmp(line, file, ft_strlen(file)) == 0
			&& ft_strlen(file) == ft_strlen(line))
		{
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	return (new_file);
}

int	ft__c__red(t_redirection *redirection)
{
	int	c__red;

	c__red = 0;
	while (redirection)
	{
		if (redirection->flag == 4)
			c__red++;
		redirection = redirection->next;
	}
	return (c__red);
}

void	ex___2(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
	{
		perror(file);
		exit(1);
	}
}

int	ft_redirection(t_box *box, t_redirection *redirection)
{
	int				find;
	t_redirection	*tmp_re;
	int				c__red;
	int				riGt_input;

	(void)box;
	tmp_re = redirection;
	c__red = ft__c__red(tmp_re);
	box->speinput_file = NULL;
	find = 0;
	riGt_input = 0;
	while (redirection)
	{
		if (redirection->flag == 4)
		{
			box->input_file = ft_s(redirection->str);
			if (box->input_file)
				riGt_input = 1;
			find++;
		}
		if (find == c__red)
		{
			if (redirection->flag == 2 && !riGt_input)
			{
				box->input_file = redirection->str;
				// printf("box->input_file: %s\n", box->input_file);
				// ex___2(box->input_file);
			}
			else if (redirection->flag == 3)
				box->output_file = redirection->str;
			else if (redirection->flag == 5)
			{
				box->output_file = redirection->str;
				box->append = 400;
			}
			return (1);
		}
		redirection = redirection->next;
	}
	return (0);
}
