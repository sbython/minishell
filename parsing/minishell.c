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
void nongnu(int i)
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

void shell_loop(char **en)
{
    char *prom;
    t_box lst ;

    lst.env = fill_env(en); 
   
    
    prom = prompt();
    lst.cmd = readline(prom);
    free(prom);
    while (lst.cmd)
    {
        free(lst.cmd);
        prom = prompt();
        lst.cmd = readline(prom);
        printf("%s",lst.cmd);
 
        free(prom);
    }
}
int main(int ac, char **av, char **env)
{
    (void)av;
    
    if(ac != 1)
    {
        write(1,"mimishell has no need more then 0 arg",38);
        return (1);
    }
    signal(SIGINT, nongnu);
    signal(SIGQUIT, SIG_IGN);
    shell_loop(env);
    return 0;    
}
