/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/26 15:06:43 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char* filter_n(char *r) 
{
    int i = 0;
    while (r[i] && r[i] != '=')
        i++;
    if (!r[i])
        return (NULL);
    char *name = malloc(i + 1);
    int j = i + 1;
    ft_strlcpy(name,r + j, -1);
    return name;
}
