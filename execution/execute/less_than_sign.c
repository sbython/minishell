/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/12 02:55:56 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    less_than_sign(t_box *box, t_com *lst)
{
    (void)box;
    // printf("%s\n", lst->com);
    // printf("ptr:  %s\n", box->l_com->com);
    // printf("less_than_sign:  %s\n", box->l_com->next->com);
    // printf("file:  %s\n", lst->com);
    int get_file;

    get_file = open(lst->com, O_RDONLY);

    if(get_file != -1)
    {
        // printf("KAYN MOJOD\n");
        execute_c_options(box);
    }
    else
    {
        perror(lst->com);
    }
}
