/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/17 09:16:25 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    length_opp(char **opp)
{
    int i;

    i = 0;
    while (opp[i])
        i++;
    return i;
}

void    execute(t_box *box)
{
   (void)box;
    int option_count = 0;
    t_command *current = box->node->command;

    // Count the total number of options across all commands
    while (current)
    {
        int t = 0;
        while (current->options[t])
        {
            option_count++;
            t++;
        }
        current = current->next;
    }

    char **cmds = (char **)malloc(sizeof(char *) * (option_count + 1));

    current = box->node->command;
    

        int k = 0;
    while (current)
    {
        int t = 0;
        while (current->options[t])
        {
            printf("%s", current->options[t]);
            cmds[k] = current->options[t];
            k++;
            t++;
        }
        printf("\n");
        current = current->next;
    }
        cmds[k] = NULL;  

    // Print the options to verify
    // int i = 0;
    // while (cmds[i])
    // {
    //     printf("%s\n", cmds[i]);
    //     i++;
    // }

    pipe_commands(box, cmds, option_count);
}
