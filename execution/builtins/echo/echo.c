/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/29 12:43:03 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int     bad_char(char *str)
{
    int i = 0;
    if(str[0] == '-')
    {
        i++;
        while (str[i])
        {
            printf("%c\n", str[i]);
            if(str[i] != 'n')
                return 0;
            i++;
        }
    }
    return 1;
}

void    rebuild_echo(t_com *t_tmp_ls, char *next)
{
    (void)t_tmp_ls;
    (void)next;
    int check;
    int bad_c;

    check = 1;
    // if(!bad_c)
    //     check = 0;
    while (t_tmp_ls->next)
    {
        t_tmp_ls = t_tmp_ls->next;
        bad_c = bad_char(t_tmp_ls->com);
    //     if(!(ft_strncmp("-n", t_tmp_ls->com, 2) == 0))
    //     {
    //         ft_putstr_fd(t_tmp_ls->com, 1);
    //         if(t_tmp_ls->next != NULL)
    //             ft_putstr_fd(" ", 1);
    //     }
    }
    printf("bad_c: %d\n", bad_c);
    // if(check)
    //     ft_putstr_fd("\n", 1);
}

// echo -nnnnnnnfnn heheh 
