/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/28 17:24:20 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_pwd(int size, t_com *ls)
{
    if(size > 1)
    {
        if(ls->next->com[0] == '-')
        {
            ft_putstr_fd("pwd: bad option: -", 1);
            ft_putchar_fd(ls->next->com[1], 1);
        
        }
        else if(ls->next->com[0] != '-')
            ft_putstr_fd("pwd: too many arguments", 1);
    }
    else
    {
        char *pwd;
        char buffer[1024];
        pwd = getcwd(buffer, sizeof(buffer));
        ft_putstr_fd(pwd, 1);
    }
    ft_putstr_fd("\n", 1);
}
