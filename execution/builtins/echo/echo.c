/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/26 18:41:11 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    procces_echo(t_com *t_tmp_ls)
{
    while (t_tmp_ls)
    {
        t_tmp_ls = t_tmp_ls->next;
        ft_putstr_fd(t_tmp_ls->com, 1);
        if(t_tmp_ls->next->com != NULL)
            ft_putstr_fd(" ", 1);
    }
}

void    echo(t_com *t_tmp_ls, char *next)
{
    (void)next;
    procces_echo(t_tmp_ls);
}
