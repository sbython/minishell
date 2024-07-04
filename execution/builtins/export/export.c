/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/04 20:31:06 by zibnoukh         ###   ########.fr       */
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
    int j = 0;
    // int k = 0;
    while (next[j])
    {
        // printf("%c", next[j]);
        new_node->name[j] = next[j];
        j++;
    }
    new_node->vale[j] = '\0';
    printf("new_node->vale: %s", new_node->vale);
}

void half_rebuild_export(env *box_env, char *next)
{
    (void)box_env;
    
    env *last;
    env *new_node = (env*)malloc(sizeof(env));
    // new_node->name = ft_strdup(next);
    // new_node->vale = ft_strdup("");
    last = ft_last(box_env);
    last->next = new_node;
    check_next(new_node, next);

    // while (box_env)
    // {
    //     printf("%s=", box_env->name);
    //     printf("%s\n", box_env->vale);
    //     box_env = box_env->next;
    // }
}

void rebuild_export(t_box *box)
{
    if(length_stack(box->l_com) < 2)
    {
        while (box->env)
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
