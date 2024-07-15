/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:13:14 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/15 16:50:25 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int  open_it(char * str,int flag, int *re)
{

    int re1[2];

    ft_bzero(re1, 2 * sizeof(int));
    if (flag == 2)
        re1[0] = open(str, O_RDONLY, 0666);
    else if(flag == 3)
        re1[1] = open(str, O_WRONLY, 0666);
    else if (flag == 4)
            (void)0;
    else if (flag == 5)
        re1[1] = open(str, O_APPEND, 0666);
    if(re1[1] == -1 || re1[0] == -1)
    {   
        printf("error %s ", str);
        perror("file not fond"); 
        return(-1);
    }
    if (re1[0] != 0)
    {
        if (re[0] != 0)
            close(re[0]);
        re[0] = re1[0];
    }
    if (re1[1] != 0)
    {
        if (re[1] != 1)
            close(re[1]);
        re[1] = re1[1];
    }
    return 0;
}


void open_1(int *re, t_redirection *file)
{
    int error;
    
    while (file)
    {
        error =  open_it(file->str, file->flag,re);
        file = file->next;
    }
    
}
