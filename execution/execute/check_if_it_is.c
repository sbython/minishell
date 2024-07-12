/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_it_is.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/12 04:39:40 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    check_if_it_is(t_box *box, char *str)
{
    (void)box;
    // printf("check_if_it_is:   %s\n",str);
    int get_file;
    int check;

    check = 1;
    get_file = open(str, O_RDONLY);

    if(get_file != -1)
    {
        check = 0;
        // printf("KAYN MOJOD\n");
    }
    else
    {
        perror(str);
    }
    box->check_val = check;
}
