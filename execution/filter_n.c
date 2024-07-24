/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 12:06:57 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char* filter_n(char *r) 
{
    int i = 0;
    while (r[i] && r[i] != '=')
        i++;
    char *name = malloc(i + 1);
    size_t j = i + 1;
    int k = 0;
    while (j < ft_strlen(r))
    {
        name[k] = r[j];
        k++;
        j++;
    }
    name[j] = '\0';
    return name;
}
