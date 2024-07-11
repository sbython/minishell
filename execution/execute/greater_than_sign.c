/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/10 06:56:26 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void ex_command(char *prev, char *next)
// {
//     (void)prev;
//     // int fd;

//     // fd = open(next, O_APPEND, O_RDONLY); 
//     printf("next of >: %s\n", next);  
// }

void    greater_than_sign(t_box *box)
{
    (void)box;
    // printf(">\n");
    // printf("prev of >: %s\n", box->l_com->com);
    // ex_command(box->l_com->com, box->l_com->next->com);
    int file = open(box->l_com->next->next->com, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file < 0) {
        ft_putstr_fd("Error opening file!\n", 1);
        return ;
    }

    // (write(file, box->l_com->com, ft_strlen(box->l_com->com)) != ft_strlen(box->l_com->com))
    int length_ = ft_strlen(box->l_com->com);
    if (write(file, box->l_com->com, ft_strlen(box->l_com->com)) != length_) {
        ft_putstr_fd("Error writing file!\n", 1);
        close(file);
        return ;
    }
    close(file);

}
