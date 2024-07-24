/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 21:52:41 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int     notN(char *n)
{
    int i;

    i = 0;
    
    if (!n)
        return (0);
    else if (n[i] == '-')
        i++;
    else 
        return (0);
    while (n[i])
    {
        if(n[i] != 'n')
            return 0;
        i++;
    }
    return 1;
}

int next_(char **s)
{
    int i;

    i = 1;
    while (notN(s[i]))
        i++;
    return (i);
}

int    rebuild_echo(char **ptr)
{
    (void)ptr;
    int i ;

    i = next_(ptr);
    while (ptr && ptr[i])
    {
        printf("%s", ptr[i]);
        i++;
        if(ptr[i])
                printf(" ");
        
    }
    if (!notN(ptr[1]) || !ptr[1])
        printf("\n");
    return (0);
}

    // printf("%s\n", box->node->command->options[1]);
    // t_command *boxy = box->node->command;
    // int length = 0;
    // while (boxy->options[length])
    // {
    //     length++;
    // }
    // if(boxy->options[0] && !boxy->options[1])
    // {
        
    // //     ft_putstr_fd("\n", 1);
    // // else
    // // {
    //     int i = 1;
    //     while (boxy->options[i] )
    //     {
    //         printf("%s", boxy->options[i]);
    //         if(i < length - 1)
    //             printf(" ");
    //         i++;
    //     }
    //     if(!notN(boxy->options[1]))
    // }