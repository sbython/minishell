/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_it_is.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/14 09:40:12 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    check_if_it_is(char *str)
{
    int get_file;
    int check;

    check = 0;
    get_file = open(str, O_RDWR | O_CREAT, 0666);

    if(get_file == -1)
        check++;
    if(check)
    {
        perror(str);
        return 1;
    }
    return 0;
}
