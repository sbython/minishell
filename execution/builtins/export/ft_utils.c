/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:46:03 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/27 14:12:51 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int f__plus(char *r)
{
    int i = 0;
    int count = 0;
    
    while (r[i])
    {
        if (r[i] == '+')
        {
            count++;
            if (r[i + 1] != '=')
                count++;
        }
        i++;
    }
    if(count > 1)
        return 0;
    return 1;
}

int ft_utils(char *ptr)
{
    int i = 0;
    if (!ft_isalpha(ptr[0]) && ptr[0] != '_')
        return 0;
    while (ptr[++i] && ptr[i] != '=')
    {
        if (ptr[i] == '+')
            break;
        else if (!ft_isalnum(ptr[i]) && ptr[i] != '_')
            return (0);
    }
    if (ptr[i] && ptr[i] == '+' && ptr[i + 1] != '=')
        return 0;
    return 1;
}
