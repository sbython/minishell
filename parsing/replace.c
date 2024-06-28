/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:11:59 by msbai             #+#    #+#             */
/*   Updated: 2024/06/28 12:21:09 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

// rep_len = len[0]
// with_len = len[1]
// len = len[2]
// result = str[0]
// res_pos = str[1]
// pos = str[2]
char * str_replace(char * s1, char *rep, char *with)
{
    size_t len[3];
    char * str[3];

    len[0] = ft_strlen(rep);
    len[1] = ft_strlen(with);
    str[0] = malloc(ft_strlen(s1) +(len[1] - len[0]) + 1);
    str[1] = str[0];
    while ((str[2] = ft_strnstr(s1, rep , -1)))
    {
        len[2] = str[2] - s1;
        ft_memcpy(str[1], s1 , len[2]);
        str[1] += len[2];
        ft_memcpy(str[1], with , len[1]);
        str[1] +=  len[1];
        s1 = str[2] + len[0];
    }
    ft_strlcpy(str[1], s1 , -1);
    return (str[0]);
}

