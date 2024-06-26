/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/06/26 09:58:35 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    get_string(char *s)
{
    // printf("s:        %s\n", s);
    char *t = ft_strdup("echo");
    while (s == t)
    {
        printf("Break\n");
    }
    
    // if(s == t)
    // {
        // printf("Break\n");   
    // }
    // else
    // {
        // printf("Siiiiiir\n");  
    // }
}

void    get_cmd_to_builtins(t_box *box)
{
    int pid;
    t_com *ls;
    
    pid = fork();
    if (!pid)
    {
        parsing(box);
        ls = box->l_com;
        if(ft_strncmp(ls->com, "echo", ft_strlen(ls->com)) == 0)
        {
            printf("hia: %s\n" ,ls->com);
        }
        else
        {
            printf("no");
        }
        while (ls)
        {
            
            // printf("%s\n", ls->com);
            // get_string(ls->com);
            ls = ls->next;
        }
        exit(0);
    }
    else
        wait(NULL);    
}

void    get_cmd(t_box *box)
{
    get_cmd_to_builtins(box);
}
