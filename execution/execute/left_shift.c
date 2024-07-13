/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:11:29 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/13 03:26:01 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	left_shift(t_box *box, t_com *l_com)
{
	const char	*delimiter = l_com->next->com;
	size_t		delimiter_len;
	char		buffer[1024];
	char		*input;
	size_t		input_size;
	size_t		buffer_index;
	size_t		delimiter_match;
	ssize_t		bytes_read;
	char		*new_input;

	(void)box;
	delimiter_len = strlen(delimiter);
	input = NULL;
	input_size = 0;
	buffer_index = 0;
	delimiter_match = 0;
	while (1)
	{
		while (1)
		{
			bytes_read = read(STDIN_FILENO, buffer + buffer_index, 1);
			if (bytes_read <= 0)
				break ;
			if (buffer[buffer_index] == delimiter[delimiter_match])
			{
				delimiter_match++;
				if (delimiter_match == delimiter_len)
					break ;
			}
			else
				delimiter_match = 0;
			buffer_index++;
			if (buffer_index == 1024)
			{
				new_input = realloc(input, input_size + buffer_index + 1);
				if (!new_input)
				{
					perror("Failed to allocate memory");
					free(input);
					exit(0);
				}
				input = new_input;
				memcpy(input + input_size, buffer, buffer_index);
				input_size += buffer_index;
				buffer_index = 0;
			}
			if (buffer[buffer_index - 1] == '\n')
				break ;
		}
		if (delimiter_match == delimiter_len)
			break ;
		if (buffer_index > 0)
		{
			new_input = realloc(input, input_size + buffer_index + 1);
			if (!new_input)
			{
				perror("Failed to allocate memory");
				free(input);
				exit(0);
			}
			input = new_input;
			ft_memcpy(input + input_size, buffer, buffer_index);
			input_size += buffer_index;
			buffer_index = 0;
		}
	}
	if (buffer_index > 0)
	{
		new_input = realloc(input, input_size + buffer_index + 1);
		if (!new_input)
		{
			perror("Failed to allocate memory");
			free(input);
			exit(0);
		}
		input = new_input;
		ft_memcpy(input + input_size, buffer, buffer_index);
		input_size += buffer_index;
	}
	execute_c_options(box);
}
