#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

void execute_command(char *command) {
    char *argv[BUFFER_SIZE];
    int argc = 0;
    char *token = strtok(command, " ");
    
    while (token != NULL) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    if (fork() == 0) {
        // In the child process
        if (execvp(argv[0], argv) == -1) {
            perror("execvp failed");
        }
        exit(EXIT_FAILURE);
    } else {
        // In the parent process
        wait(NULL);
    }
}

int main(int argc, char *argv[]) {
    //     return 1;
    // }

    char cwd[1024];
    // if (
        getcwd(cwd, sizeof(cwd));
        // != NULL
        // ) {
    //     printf("Changed directory to: %s\n", cwd);
    // } else {
    //     perror("getcwd failed");
    //     return 1;
    // }

    char command[1024];
    while (1) {
        printf("%s> ", cwd);
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("fgets failed");
            break;
        }
        // Remove the newline character at the end of the command
        // command[strcspn(command, "\n")] = '\0';

        // Exit the shell if the user types "exit"
        // if (strcmp(command, "exit") == 0) {
        //     break;
        // }

        execute_command(command);

        // Update the current working directory
        // if (getcwd(cwd, sizeof(cwd)) == NULL) {
        //     perror("getcwd failed");
        //     break;
        // }
    }

    return 0;
}
