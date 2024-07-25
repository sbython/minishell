/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/23 22:32:06 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	open_all_files(t_redirection *red)
{
	int	fd;

	while (red)
	{
		fd = open(red->str, O_RDONLY, 0666);
		if (fd == -1)
		{
			perror(red->str);
			// exit(0);
		}
		// printf("%s\n", red->str);
		red = red->next;
	}
}
