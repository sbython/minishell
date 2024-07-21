/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/21 16:05:56 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char*   random_file(char *file)
{
    char *new_file;
    char *join_file;
    
    int i = 0;
    new_file = malloc(sizeof(file) + 1);
    while (file[i])
    {
        if(file[i] >= 'a' && file[i] <= 'z')
            file[i] -= 32;
        new_file[i] = file[i];
        i++;
    }
    new_file[i] = '\0';

    join_file = ft_strjoin(ft_strjoin("/tmp/0X", ft_itoa(ft_strlen(file) * 1060 / 10)), new_file);
    
    return join_file;
}
