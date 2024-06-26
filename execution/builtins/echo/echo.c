/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/26 11:52:48 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    print_echo(char *s)
{
    int i;

    i = 0;
    while (s[i])
        write(1, &s[i++], 1);
}

t_com   *last_node(t_com *t_tmp_ls)
{
    while (/* condition */)
    {
        /* code */
    }
    
}

void    echo(t_com *t_tmp_ls, char *next)
{
    (void)next;
    // printf("next: %s\n", next);
    int count;

    count = 0;
    while (t_tmp_ls)
    {
        // printf("hanta: %s\n", t_tmp_ls->com);
        count++;
        t_tmp_ls = t_tmp_ls->next;
        // if(t_tmp_ls->next->com == "test")
        // if(!(ft_strncmp(t_tmp_ls->next->com, NULL, ft_strlen(t_tmp_ls->next->com)) == 0))
        //     print_echo(" ");
        // print_echo(t_tmp_ls->com);
        // print_echo(t_tmp_ls->next->com);
        // ft_putstr_fd(" ", 1);
        // ft_strlcat()
        // ft_putstr_fd("\n", 1);
        // if(!(ft_strncmp("-n", next, ft_strlen(next)) == 0))
    }
    printf("%d\n", count);
    // write(1, "\n", 1);
}

// 1: print all strings [ex ex ex]
