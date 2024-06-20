/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbython <sbython@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/06/19 07:19:23 by sbython          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void nongnu(int i)
{
    if (i == SIGINT)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void shell_loop(char **en)
{
    char *prom;
    t_box lst ;

    lst.env = fill_env(en); 
   
    

    while (1)
    {
        prom = prompt();  
        lst.cmd = readline(prom);
        add_history(lst.cmd);
        if(!lst.cmd)
        { 
            free(prom);
            break;
        }
        get_cmd(&lst);
        free(prom);
    }
    free_all(&lst);
}
int main(int ac, char **av, char **env)
{
    (void)av;
    
    if(ac != 1)
    {
        write(1,"mimishell has no need any arg",30);
        return (1);
    }
    signal(SIGINT, nongnu);
    signal(SIGQUIT, SIG_IGN);
    shell_loop(env);
    return 0;    
}
