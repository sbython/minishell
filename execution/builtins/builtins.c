/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 21:41:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    builtins(char **ptr, t_env *env__)
{
    int status;

    status = 0;
    if(ft_strncmp(ptr[0], "cd", -1) == 0)
        status = rebuild_cd(ptr, env__);
    else if(ft_strncmp(ptr[0], "echo", -1) == 0)
        status = rebuild_echo(ptr);
    else if(ft_strncmp(ptr[0], "pwd", -1) == 0)
        status = rebuild_pwd(ptr);
    else if(ft_strncmp(ptr[0], "env", -1) == 0)
        status = rebuild_env(ptr, env__);
    else if(ft_strncmp(ptr[0], "exit", -1) == 0)
        status = rebuild_exit(ptr, ptr[1]);
    else if(ft_strncmp(ptr[0], "export", -1) == 0)
        status = rebuild_export(ptr);
    else if(ft_strncmp(ptr[0], "unset", -1) == 0)
        status = rebuild_unset(ptr);
    return 0;
}
