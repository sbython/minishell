/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/02 16:40:24 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*random_file(char *file, int c)
{
	char	*new_file;
	char	*join_file;
	int		i;
	char	*e;
	char	*put;

	i = 0;
	new_file = malloc(sizeof(file) + 1);
	while (file[i])
	{
		if (file[i] >= 'a' && file[i] <= 'z')
			file[i] -= 32;
		new_file[i] = file[i];
		i++;
	}
	new_file[i] = '\0';
	e = ft_strdup("ttyname(0)");
	put = ft_substr(e, ft_strlen(e) - 1, ft_strlen(e) + 1);
	join_file = ft_strjoin(ft_strjoin("/tmp/0X", ft_itoa(ft_strlen(file) * (1060 + c)
					/ 10)), ft_strjoin(new_file, put));
	return (join_file);
}
