/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/05/23 16:35:39 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void nonfun(int i)
{
    char *prom;
    if (i == SIGINT)
    {
        write(0,"\n", 1);
        prom = prompt();
        write(0,prom, ft_strlen(prom));
        free(prom);
    }
    
}
int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    char *prom;
    t_box lst ;
    
    signal(SIGINT, nonfun);
    signal(SIGQUIT, SIG_IGN);
    prom = prompt();
    lst.cmd = readline(prom);
    free(prom);
    while (lst.cmd)
    {
        get_cmd(&lst);
        free(lst.cmd);
        prom = prompt();
        lst.cmd = readline(prom);
        if (lst.cmd[0] == '1')
            rl_on_new_line();
        free(prom);
    }
    return 0;    
}
