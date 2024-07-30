/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_heardocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/30 11:43:12 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft___(char *file, int i)
{
	char	*cpy_str_val;
	char	*new_file;
	char	*promptt;
	int		fd;
	char	*line;

	cpy_str_val = ft_strdup(file);
	new_file = random_file(cpy_str_val, i);
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

char **run_all_heardocs(t_box *box) 
{
    int i = 0;
    int j = 0;
	int k = 0;
    t_command *tmp = box->node->command;
    char **files = (char **)malloc(sizeof(char *) * (how_her(box) + 1));
    if (!files) 
	{
        perror("malloc");
        return NULL;
    }
	
    while (tmp) 
	{
        // int pid = fork();
        // if(pid == -1)
        // {
        //     perror("fork failed");
        //     exit(0);
        // }
        // else if (pid == 0)
        // {
			t_redirection *red_tmp = tmp->redirection;
			char *last_file = NULL;
			while (red_tmp) 
			{
				if (red_tmp->flag == 4) 
				{ 
					if (last_file) 
						free(last_file);
					last_file = ft___(red_tmp->str, i);
					if (!last_file) 
					{
						k = 0;
						while (k < j) 
						{
							free(files[k]);
							k++;
						}
						free(files);
						return NULL;
					}
					i++;
				}
				else
					last_file = ft_strdup("");
				red_tmp = red_tmp->next;
			}
			if (last_file) 
				files[j++] = last_file;
			// exit(0);
		// exit(0);
		// }
		tmp = tmp->next;
    }

	// while (wait(NULL) > 0)
	// {

	// };

    files[j] = NULL;
    return files;
}
