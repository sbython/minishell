/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/07 00:15:34 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char* filter_v(char *r) 
{
    int i = 0;
    char *vale;
    int     j;
    while (r[i] && r[i] != '=')
        i++;
    if (!r[i])
        return (NULL);
    j = i + 1;  
    vale = malloc(ft_strlen(r + j) + 1);
    ft_memcpy(vale,(r + j), ft_strlen(r + j));
    vale[ft_strlen(r + j)] = 0;
    return vale;
}
