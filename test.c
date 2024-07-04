/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:56:07 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/04 23:34:16 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];

    if (chdir(path) != 0) {
        perror("chdir failed");
        return 1;
    }

    char *shell = getenv("SHELL");
    // if (shell == NULL) {
    //     shell = "/bin/sh"; // Default to /bin/sh if SHELL environment variable is not set
    // }

    execlp(shell, shell, (char *)NULL); // Replace the current process with the shell

    perror("execlp failed"); // If execlp fails, print an error message
    return 1;
}
