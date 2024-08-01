/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/01 18:46:28 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*dev_ran(char buffer[21])
{
	char *r = malloc(22);
	int i = 0;

	while (buffer[i])
	{
		if(buffer[i] > 33 && buffer[i] < 127)
			r[i] = buffer[i];
		i++;
	}
	r[i] = '\0';
	return r;
}

char	*random_file(char *file, int c)
{
	char	*new_file;
	char	*join_file;
	int		i;
	char	*e;
	char	*put;
	int fd = open("/dev/random", O_RDONLY);
	char buffer[21];
	if(read(fd, buffer, 20) == 20)
	{
		perror("open");
		close(fd);
		return NULL;
	}
	i = 0;
	(void)c;
	new_file = malloc(sizeof(file) + 1);
	while (file[i])
	{
		if (file[i] >= 'a' && file[i] <= 'z')
			file[i] -= 32;
		new_file[i] = file[i];
		i++;
	}
	new_file[i] = '\0';
	e = ft_strdup(ttyname(0));
	put = ft_substr(e, ft_strlen(e) - 1, ft_strlen(e) + 1);
	join_file = ft_strjoin(ft_strjoin("/tmp/0X", ft_itoa(ft_strlen(file) * (1060 + c)
					/ 10)), ft_strjoin(new_file, put));
	return (join_file);
}
