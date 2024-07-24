/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 15:21:22 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_env *create_env_node(char *name, char *value) 
{
    t_env *new_node = malloc(sizeof(t_env));
    if (!new_node) 
    {
        perror("malloc");
        exit(0);
    }
    new_node->name = ft_strdup(name);
    new_node->vale = ft_strdup(value);
    new_node->next = NULL;
    return new_node;
}

void add_env_variable(t_box *box, char *name, char *value) 
{
    t_env *new_node = create_env_node(name, value);
    if (!box->env) 
        box->env = new_node;
    else 
    {
        t_env *current = box->env;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void rebuild_export(t_box *box)
{
    (void)box;
   t_env *expo_env;
//    int exicted = 0;
//    char * new_name;
//    char * new_vale;

   if(box->node->command->options[1])
   {
        box->export_val = filter_v(box->node->command->options[1]);
        box->export_name = filter_n(box->node->command->options[1]);
        // add_env_variable(box, box->export_val, box->export_name); 
   }
//    if(box->node->command->options[0] && !box->node->command->options[1])
//    {
//     new_name = box->export_name;
//     new_vale = box->export_val;

    // printf("new_name %s\n", new_name);
    // printf("new_vale %s\n", new_vale);
    expo_env = box->env;
    while (expo_env != NULL)
    {
        // if(ft_strncmp(expo_env->name, new_name, 4) == 0 && ft_strlen(expo_env->vale) != 0)
        // {
        //     expo_env->name = new_name;
        //     expo_env->vale = new_vale;
        // }

        ft_putstr_fd("declare -x ", 1);
        ft_putstr_fd(expo_env->name, 1);
        if(ft_strlen(expo_env->vale) != 0)
            ft_putstr_fd("=", 1); 
        ft_putstr_fd(expo_env->vale, 1);
        ft_putstr_fd("\n", 1);
        expo_env = expo_env->next;
    }
//    }
//    printf("mawjoud: %d\n", mawjoud);
}
