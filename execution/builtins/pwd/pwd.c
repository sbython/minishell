/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 10:30:13 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_pwd(t_box *box)
{
    (void)box;
    char *pwd;
    char buffer[1024];
    pwd = getcwd(buffer, sizeof(buffer));
    ft_putstr_fd(pwd, 1);
    ft_putstr_fd("\n", 1);
}
