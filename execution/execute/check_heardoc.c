/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heardoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/20 15:09:23 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    check_heardoc(t_redirection *redirection)
{
    while (redirection)
    {
        if(redirection->flag == 4 || redirection->flag == 5)
            return 1;
        redirection = redirection->next;
    }
    return 0;
}
