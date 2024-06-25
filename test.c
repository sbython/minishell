#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>

char *expand_tilde(const char *str);

int main() {
    const char *str = "~/projects/minishell";
    const char *str2 = "~newuser/projects/minishell";
    
    char *result1 = expand_tilde(str);
    printf("Result1: %s\n", result1);
    free(result1);
    
    char *result2 = expand_tilde(str2);
    printf("Result2: %s\n", result2);
    free(result2);
    
    return 0;
}

char *expand_tilde(const char *str) {
    if (str[0] != '~') {
        return strdup(str); // No tilde, return a copy of the original string
    }

    const char *home = NULL;
    if (str[1] == '/' || str[1] == '\0') {
        // Case: "~" or "~/..."
        home = getenv("HOME");
        if (!home) {
            struct passwd *pw = getpwuid(getuid());
            home = pw ? pw->pw_dir : "";
        }
    } else {
        // Case: "~username"
        const char *username = str + 1;
        const char *end = strchr(username, '/');
        size_t user_len = end ? (size_t)(end - username) : strlen(username);

        char *user = strndup(username, user_len);
        if (!user) {
            perror("strndup");
            exit(EXIT_FAILURE);
        }

        struct passwd *pw = getpwnam(user);
        free(user);
        if (pw) {
            home = pw->pw_dir;
        } else {
            // User not found, return the original string
            return strdup(str);
        }
    }

    // Allocate memory for the new string
    size_t home_len = strlen(home);
    size_t str_len = strlen(str);
    size_t suffix_len = str_len - (strchr(str, '/') - str);
    char *result = malloc(home_len + suffix_len + 1);
    if (!result) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Construct the new string
    strcpy(result, home);
    strcat(result, strchr(str, '/') ? strchr(str, '/') : "");

    return result;
}
