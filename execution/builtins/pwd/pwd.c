/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 19:03:24 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int    rebuild_pwd(char **ptr)
{
    (void)ptr;
    char *pwd;
    char buffer[1024];
    pwd = getcwd(buffer, sizeof(buffer));
    ft_putstr_fd(pwd, 1);
    ft_putstr_fd("\n", 1);
    return 0;
}
