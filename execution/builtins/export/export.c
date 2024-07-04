/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 22:47:32 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

env	*ft_last(env *lst)
{
	env	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void check_next(env *new_node, char *next)
{
    new_node->vale = malloc(ft_strlen(next) + 1);
    new_node->name = malloc(ft_strlen(next) + 1);

    int i = 0;
    int count = 0;
    while (next[i])
    {
        if(next[i] == '=')
        {
            count++;            
            break;
        }
        new_node->name[i] = next[i];
        i++;
    }
    new_node->name[i] = '\0';

    int j = i + 1;
    int k = 0;
    while (next[j])
    {
        new_node->vale[k] = next[j];
        k++;
        j++;
    }
    new_node->position = count;
}

void half_rebuild_export(env *box_env, char *next)
{
    (void)box_env;
    
    env *last;
    env *new_node = (env*)malloc(sizeof(env));
    last = ft_last(box_env);
    last->next = new_node;
    check_next(new_node, next);
    // printf("%d\n", new_node->position);
    while (box_env)
    {
        ft_putstr_fd(box_env->name, 1);
        // if(new_node->position)
            // ft_putstr_fd("=", 1);
        // else
            // ft_putstr_fd("X", 1);
        
        ft_putstr_fd("=", 1);
        ft_putstr_fd(box_env->vale, 1);
        ft_putstr_fd("\n", 1);
        box_env = box_env->next;
    }
}

void rebuild_export(t_box *box)
{
    if(length_stack(box->l_com) < 2)
    {
        while (box)
        {
            ft_putstr_fd("declare -x ", 1);
            ft_putstr_fd(box->env->name, 1);
            ft_putstr_fd("=", 1);
            ft_putstr_fd(box->env->vale, 1);
            ft_putstr_fd("\n", 1);
            box->env = box->env->next;
        }
    }
    else
    {
        half_rebuild_export(box->env, box->l_com->next->com);
    }
}
