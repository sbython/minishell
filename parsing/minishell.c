/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 19:52:31 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void nongnu(int i)
{
    if (i == SIGINT)
    {
        write(0,"\n", 1 );
        rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
    }
}

void shell_loop(char **en)
{
    char *prom;
    t_box lst ;

    memset((void *)&lst, 0, sizeof(t_box));
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
        free_all(&lst);  
    }
    rl_clear_history();
    free_env(lst.env);
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
