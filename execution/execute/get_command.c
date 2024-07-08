/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/08 23:32:21 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    get_command(t_command *command)
{
    // (void)command;
    // printf("HERO\n");
    // get_redirection(command->redirection);
    get_options(command->options);
    // while (command)
    // {
    
    //     printf(" node->exit_nb: %d\n", command->);
    //     command = command->next;
    // }
}
