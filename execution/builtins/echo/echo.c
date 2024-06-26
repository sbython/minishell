/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/26 11:33:55 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    echo(t_com *t_tmp_ls, char *next)
{
    (void)next;
    // printf("next: %s\n", next);
    int count;

    count = 0;
    while (t_tmp_ls)
    {
        // printf("hanta: %s\n", t_tmp_ls->com);
        t_tmp_ls = t_tmp_ls->next;
        count++;
        // ft_putstr_fd(t_tmp_ls->com, 1);
        // ft_putstr_fd(" ", 1);
        // ft_strlcat()
        // ft_putstr_fd("\n", 1);
        // if(!(ft_strncmp("-n", next, ft_strlen(next)) == 0))
    }
    printf("%d\n", count);
    // write(1, "\n", 1);
}



// 1: print all strings [ex ex ex]
