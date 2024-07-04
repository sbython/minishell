/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join2pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:48:54 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 02:06:45 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t ft_len2(char ** s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char **join2pointer(char **com, char *str)
{
    size_t len2 = ft_len2(com);
    char **new_com = ft_calloc((len2 + 2), sizeof(char *));
    int i = 0;
    
    while (com && com[i])
    {
        new_com[i] = com[i];
        i++;    
    }
    new_com[i++] = str;
    new_com[i] = NULL;
    free(com);
    return (new_com);
}