/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbython <sbython@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/24 09:01:55 by sbython          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    get_cmd(t_box *box)
{
    int pid;
    t_com *ls;
    
    pid = fork();
    if (!pid)
    {
        parsing(box);
        ls = box->l_com;
        while (ls)
        {
            printf("%s\n", ls->com);
            ls = ls->next;
        }
        exit(0);
    }
    else
        wait(NULL);
}
