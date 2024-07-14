/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gitpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 06:55:43 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 08:19:24 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_pid1(char *str)
{
	int		i;
	char	*tmp;
	char	*tmp1;
	char	**split;

	i = 0;
	tmp1 = ft_strnstr(str, "Pid:", -1);
	tmp = ft_strchr(tmp1, '\n');
	*tmp = 0;
	split = ft_split(tmp1, '\t');
	tmp1 = split[1];
	free(split[0]);
	free(split);
	free(str);
	return (tmp1);
}

char	*get_pid(void)
{
	int		fd;
	char	*str;
	ssize_t	status;

	str = ft_calloc(sizeof(char), 101);
	if (!str)
		return (perror("malloc error"), NULL);
	fd = open("/proc/self/status", O_RDONLY);
	if (fd == -1)
		return (perror("open file error"), NULL);
	status = read(fd, str, 100);
	close(fd);
	if (status == -1)
		return (perror("read file error"), NULL);
	str = get_pid1(str);
	return (str);
}
