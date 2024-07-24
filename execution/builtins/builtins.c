/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 10:31:31 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    builtins(t_box *box)
{
    if(ft_strncmp(box->node->command->options[0], "cd", 2) == 0)
        rebuild_cd(box);
    else if(ft_strncmp(box->node->command->options[0], "echo", 4) == 0)
        rebuild_echo(box);
    else if(ft_strncmp(box->node->command->options[0], "pwd", 3) == 0)
        rebuild_pwd(box);
    else if(ft_strncmp(box->node->command->options[0], "env", 3) == 0)
        rebuild_env(box);
    else if(ft_strncmp(box->node->command->options[0], "exit", 3) == 0)
        rebuild_exit(box);
}
