/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:56:07 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/08 03:20:07 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
#include <sys/wait.h>

char * get_pid();

int main() {
    char * p;

    int i = fork();
    
    p = get_pid();
    printf("%s\n", p);
    free (p);
    printf("%d\n", getpid());
    if (!i)
    {
         printf("%s\n", p);
        free (p);
        printf("%d\n", getpid());
    }
    else 
        wait(NULL);
    return 0;
}