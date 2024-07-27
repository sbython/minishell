/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 10:05:32 by zibnoukh         ###   ########.fr       */
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
    vale = malloc(i + 1);
    j = i + 1;
    ft_strlcpy(vale,r + j, -1);
    return vale;
}
