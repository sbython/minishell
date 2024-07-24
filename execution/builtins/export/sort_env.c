/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/24 14:18:28 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int count_env(t_env *env) 
{
    int count = 0;
    while (env) {
        count++;
        env = env->next;
    }
    return count;
}

t_env* sort_env(t_env *env)
{
    int count = count_env(env);
    t_env **env_array = malloc(count * sizeof(t_env *));

    t_env *current = env;
    int i = 0;
    while ( i < count)
    {
        env_array[i] = current;
        current = current->next;
        i++;
    }

    i = 0;
    while ( i < count - 1) 
    {
        int j = 0;
        while ( j < count - 1 - i) 
        {
            if (ft_strncmp(env_array[j]->name, env_array[j + 1]->name, ft_strlen(env_array[j]->name)) == 0) 
            {
                t_env *temp = env_array[j];
                env_array[j] = env_array[j + 1];
                env_array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }

    return *env_array;
}

// t_env*    sort_env(t_env *env)
// {
//     return sort_env_all(env);
// }
