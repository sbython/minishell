/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/27 16:51:39 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char* filter_n(char *r) 
{
    int i;
    char *val;

    i = 0;
    while (r[i] && r[i] != '=')
        i++;
    val = malloc(i + 1);
    int j = 0;
    while (j < i)
    {
        if(r[j] != '+')
            val[j] = r[j];
        j++;
    }
    val[j] = '\0';
    return val;
}
