/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:12:40 by msbai             #+#    #+#             */
/*   Updated: 2024/05/20 11:49:04 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    char *line;
    line = NULL;
    t_box lst ;
    // printf("┌──(sbai㉿zibnouch)-[/nfs/homes/aelkheta/Desktop/minishell]\n");
    line = readline("┌──(sbai㉿zibnouch)-[/nfs/homes/aelkheta/Desktop/minishell]\n└─$ ");
    while (line)
    {
        lst.cmd = line;
        get_cmd(&lst);
        free(line);
        
    // printf("┌──(sbai㉿zibnouch)-[/nfs/homes/aelkheta/Desktop/minishell]\n");

    //    line = readline("└─$ ");
        line = readline("┌──(sbai㉿zibnouch)-[/nfs/homes/aelkheta/Desktop/minishell]\n└─$ ");
    }
    return 0;    
}
