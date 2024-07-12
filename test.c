/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:32:48 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/13 00:32:59 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

char *ft_strjoin(const char *s1, const char *s2) {
    char *result;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    result = malloc(len1 + len2 + 1);
    if (!result) return NULL;

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

int main() {
    pid_t pid;
    int status;
    int fd;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        char *path = "/bin/";
        char *command = "ls";
        char *full_path = ft_strjoin(path, command);
        
        if (dup2(fd, STDOUT_FILENO) == -1) {
            perror("dup2");
            return 1;
        }
        
        close(fd);

        char *args[] = {command, NULL};
        if (execve(full_path, args, NULL) == -1) {
            perror("execve");
            return 1;
        }
    } else {
        close(fd);
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return 1;
        }
    }

    return 0;
}
