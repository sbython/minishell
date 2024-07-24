/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:19 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 20:05:00 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*gethost(void)
{
	int		fd;
	char	buffer[120];
	ssize_t	i;
	char	*hname;

	fd = open("/etc/hostname", O_RDONLY);
	if (fd == -1)
		return (ft_strdup("X"));
	i = read(fd, buffer, 120);
	if (i == -1)
	{
		close(fd);
		return ("X");
	}
	buffer[i - 1] = 0;
	hname = ft_strdup(buffer);
	close(fd);
	return (hname);
}

void	join(char **dest, char *src, int i)
{
	char	*tmp;

	if (!src)
		src = "X";
	tmp = ft_strjoin(*dest, src);
	free(*dest);
	if (i)
		free(src);
	*dest = tmp;
}

char	*prompt(void)
{
	char	*s;
	char	tmp[1000];

	ft_bzero(tmp, 1000);
	s = ft_strdup(GREENF);
	join(&s, getenv("LOGNAME"), 0);
	join(&s, ft_strdup("@"), 1);
	join(&s, gethost(), 1);
	join(&s, ft_strdup(" "), 1);
	getcwd(tmp, 1000);
	join(&s, tmp, 0);
	join(&s, ft_strdup(":$ "), 1);
	join(&s, ft_strdup(DCOLORF), 1);
	return (s);
}
