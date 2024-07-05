/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdTest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/05 02:53:33 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    char buffer[1024];

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", av[0]);
        return 1;
    }

    if (chdir(av[1]) != 0)
    {
        perror("chdir");
        return 1;
    }

    if (getcwd(buffer, sizeof(buffer)) != NULL)
    {
        printf("Current directory: %s\n", buffer);
    }
    else
    {
        perror("getcwd");
        return 1;
    }
    return 0;
}

