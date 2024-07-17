/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/17 11:24:38 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void    get_next(t_command  *next)
// {
//     // printf("next: %s\n", next->options);
//     int i = 0;
//     while (next->options[i])
//     {
//         printf("next option: %s\n", next->options[i]);
//         i++;
//     }
// }

void    get_command(t_command *command)
{
    // (void)command;
    // printf("HERO\n");
    // get_redirection(command->redirection);
    get_options(command->options);
    // get_next(command->next);
}
