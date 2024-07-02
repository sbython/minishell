/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/02 15:02:49 by zibnoukh         ###   ########.fr       */
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

// void    rebuild_export(t_com *ls, env *all_env, char *next)
// {
//     if(!all_env)
//         return ;
//     if(length_stack(ls) < 2)
//     {
//         while (all_env)
//         {
//             ft_putstr_fd("declare -x ", 1);
//             ft_putstr_fd(all_env->name, 1);
//             ft_putstr_fd("=", 1);
//             ft_putstr_fd(all_env->vale, 1);
//             ft_putstr_fd("\n", 1);
//             all_env = all_env->next;
//         }
//     }
//     else
//     {
//         printf("TEST\n");
//     }
//     (void)next;
//     (void)all_env;
//     // env *new_node = (env*)malloc(sizeof(env));
//     // new_node->name = "TATA";
//     // new_node->vale = "TITI";

//     // env* last;

//     // last = ft_last(all_env);

//     // last->next = new_node;
//     // printf("the last: %s\n", last->name);

//     // while (all_env)
//     // {
//     //     printf("%s=", all_env->name);
//     //     printf("%s\n", all_env->vale);
//     //     all_env = all_env->next;
//     // }
    
// }

void check_next(env *new_node, char *next)
{
    (void)new_node;
    int end;
    int start;

    end = 0;
    start = 0;
    while (next[end] != '=')
        end++;
    
    while (start < end)
    {
        new_node->name[start] = next[start];
        start++;
    }
    new_node->name[start] = 0;
    int newEnd = end + 2;
    int endend = ft_strlen(next) - 1;
    while (newEnd < endend)
    {
        // printf(next[ne])
        // new_node->name[newEnd] = next[newEnd];
        // printf("%c", new_node->name[newEnd]);
        newEnd++;
    }
    
    printf("new_node->vale: %s\n", new_node->name);
    // printf("new_node->vale: %s\n", new_node->vale);
    
}

void half_rebuild_export(env *box_env, char *next)
{
    (void)box_env;
    
    // env *last;
    // env *new_node = (env*)malloc(sizeof(env));
    // new_node->name = ft_strdup(next);
    // new_node->vale = ft_strdup("");
    // last = ft_last(box_env);
    // last->next = new_node;
    // check_next(new_node, next);
    printf("%s\n", next);

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
