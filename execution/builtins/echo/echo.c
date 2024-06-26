/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/28 17:33:29 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_echo(t_com *t_tmp_ls, char *next)
{
    int check;

    check = 1;
    if(ft_strncmp("-n", next, 2) == 0)
        check = 0;
    while (t_tmp_ls->next)
    {
        t_tmp_ls = t_tmp_ls->next;
        if(!(ft_strncmp("-n", t_tmp_ls->com, 2) == 0))
        {
            ft_putstr_fd(t_tmp_ls->com, 1);
            if(t_tmp_ls->next != NULL)
                ft_putstr_fd(" ", 1);
        }
    }
    if(check)
        ft_putstr_fd("\n", 1);
}

// echo -nnnnnnnfnn heheh 