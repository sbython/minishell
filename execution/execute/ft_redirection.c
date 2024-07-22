/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 20:34:16 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    ft_redirection(t_box*box, t_redirection *redirection)
{
    while (redirection)
    {
        if(redirection->flag == 2)
            box->input_file = redirection->str;
        else if(redirection->flag == 3)
            box->output_file = redirection->str;
        else if(redirection->flag == 4)
            box->input_file = redirection->str;
        else if(redirection->flag == 5)
            box->output_file = redirection->str;
        redirection = redirection->next;
    }
}
