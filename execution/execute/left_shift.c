/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:11:29 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/15 18:10:06 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void generate_temp_filename(char *temp_file)
{
    ft_strlcpy(temp_file, "temp_file", ft_strlen(temp_file));
}

void left_shift(t_box *box, char *delimiter)
{
    (void)box;
    int fd;
    char *line;
    const char *prompt = "> ";
    char temp_file[30]; 

    generate_temp_filename(temp_file);

    fd = open(temp_file, O_CREAT | O_RDWR , 0666);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    while ((line = readline(prompt)) != NULL)
    {
        if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
        {
            free(line);
            box->done_heardoc = 1;
            break;
        }

        int len = ft_strlen(line);
        int written = write(fd, line, len);
        if (written != len || write(fd, "\n", 1) == -1)
        {
            perror("write");
            return;
        }
        free(line);
    }

    close(fd);

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(0);
    }
    else if (pid == 0)
    {
        fd = open(temp_file, O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            exit(0);
        }

        if (dup2(fd, 0) == -1)
        {
            perror("dup2");
            exit(0);
        }

        close(fd);

        char **r = get_path(box->env);
        char *full_path = get_full_path__(box, r);
        if (execve(full_path, box->node->command->options, box->full_env) == -1)
        {
            perror("execve");
            exit(0);
        }
    }
    else
    {
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            exit(0);
        }
        unlink(temp_file);
    }
}
