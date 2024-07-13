/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/13 01:41:24 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    type_of_exe(t_box *box, t_com *l_com)
{
    (void)box;
    while (l_com)
    {
        if(l_com->type == 2)
        {
            less_than_sign(box->node->command->options);
            break;
        }
        else if(l_com->type == 3)
            greater_than_sign(box, l_com);
        else if(l_com->type == 4)
            left_shift(box, l_com);
        else if(l_com->type == 5)
            right_shift(box, l_com);
        // else
        //     printf("IDONO\n");
        // printf("%s\n", l_com->com);
        l_com = l_com->next;
    }
}
