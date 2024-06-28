#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *cwd;
    char buffer[1024];

    // Get the current working directory
    cwd = getcwd(buffer, sizeof(buffer));

    // If getcwd() returns NULL, an error occurred
    // if (cwd == NULL) {
        // perror("getcwd() error");
        // return 1;
    // } else {
        // Print the current working directory
        printf("%s\n", cwd);
    //     return 0;
    // }
}
