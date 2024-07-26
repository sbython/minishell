/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/26 07:57:11 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	swap_nodes(t_env *a, t_env *b)
{
	char	*tmp_name;
	char	*tmp_vale;

	tmp_name = a->name;
	tmp_vale = a->vale;
	a->name = b->name;
	a->vale = b->vale;
	b->name = tmp_name;
	b->vale = tmp_vale;
}

t_env* cpy_list(t_env *env)
{
    t_env* new_list = NULL;
    t_env* the_last_ = NULL;
    
    while (env)
    {
        t_env* new_node = (t_env *)malloc(sizeof(t_env));

        new_node->name = ft_strdup(env->name);
		new_node->vale = ft_strdup(env->vale);
        new_node->next = NULL;

        if (!new_list)
            new_list = new_node;
        else
            the_last_->next = new_node;
        the_last_ = new_node;
        
        env = env->next;
    }
    
    return new_list;
}

t_env*	sort_env(t_env *env)
{
	t_env* new_env = cpy_list(env);

	t_env	*curr;
	int		is_swap;
    
	if (!new_env)
        return NULL;
	while (1)
	{
		is_swap = 0;
		curr = new_env;
		while (curr->next != NULL)
		{
			if (ft_strncmp(curr->name, curr->next->name,
					ft_strlen(curr->name)) > 0)
			{
				swap_nodes(curr, curr->next);
				is_swap = 1;
			}
			curr = curr->next;
		}
		if (!is_swap)
			break ;
	}
	return new_env;
}
