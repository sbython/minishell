/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:56:07 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/21 11:57:19 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include <stdio.h>
// # include <stdlib.h>
// # include "libft/libft.h"
// # include <readline/readline.h>
// # include <readline/history.h>
// # include <limits.h>
// # include <unistd.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <signal.h>
// #include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>


int main(int ac , char **av, char **env) {
    
    char *cmd = "/usr/bin/bash";
    // char *opt[] = {"bash", "test.sh", "hello", "world", NULL};
    execve(cmd, av + 1, env);
    printf("it's failed \n");
}