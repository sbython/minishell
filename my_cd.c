/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:56:07 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/05 03:02:03 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ARGS 64
#include <stdio.h>
#include <unistd.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // for malloc, free
#include <limits.h> // for PATH_MAX

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) != 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Optionally, if you want to print the current working directory after changing:
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Changed directory to: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    // Here you can perform other operations in the new directory if needed

    return 0;
}
