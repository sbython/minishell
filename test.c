/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:56:07 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/15 11:37:12 by msbai            ###   ########.fr       */
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

volatile sig_atomic_t got_sigint = 0;

void sigint_handler(int sig) {
    got_sigint = 1;
}

int main() {
    char *input;

    // Set up signal handler for SIGINT (Ctrl+C)
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sa.sa_flags = MASK;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    while (1) {
        input = readline("Enter text (Ctrl+C to get a new prompt): ");

        // Check for EOF or error
        if (input == NULL) {
            printf("\nEOF or read error encountered\n");
            break;
        }

        // Print the input received
        printf("You entered: %s\n", input);

        // Free the input buffer allocated by readline
        free(input);

        // Check if Ctrl+C was pressed
        if (got_sigint) {
            printf("\nCtrl+C pressed. Getting a new prompt...\n");
            break;
            got_sigint = 0;  // Reset the flag
        }
    }

    printf("Program exiting.\n");
    return EXIT_SUCCESS;
}