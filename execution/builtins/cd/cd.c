/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 23:52:26 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void    rebuild_cd(t_box *box)
{
    (void)box;
    char buffer[1024];
    
    chdir(box->l_com->next->com);
    // char *shell = getenv("SHELL");
    // if(shell != NULL)
    //     shell = "/bin/sh";
    // execlp(shell, shell, NULL);
    if(getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("%s\n", buffer);
    }
}
