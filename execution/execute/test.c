/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/03 16:19:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft___kk(t_box* box, char *file, int i)
{
    char *new_file;
    char *cpy_str_val;
    cpy_str_val = ft_strdup(file);
    new_file = random_file(cpy_str_val, i);
    int fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    
    char *line;
    while ((line = readline("> ")) != NULL)
    {
        if (ft_strncmp(line, file, ft_strlen(file)) == 0 && ft_strlen(file) == ft_strlen(line))
        {
            free(line);
            break;
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
    close(fd);

    box->new_file_val = new_file;  // Store new file name in box
    return 0;
}

int run_all_heardocs2(t_box *box)
{
    int i = 0, j = 0;
    t_command *tmp = box->node->command;
    char **r = (char **)malloc(sizeof(char *) * (how_her(box) + 1));
    if (!r)
    {
        perror("malloc");
        return -1;
    }

    while (tmp)
    {
        t_redirection *red_tmp = tmp->redirection;
        char *last_file = NULL;
        while (red_tmp)
        {
            if (red_tmp->flag == 4)
            {
                if (last_file)
                    free(last_file);
                if (ft___kk(box, red_tmp->str, i) != 0)
                {
                    free(r);
                    return -1;
                }
                last_file = ft_strdup(box->new_file_val);  // Duplicate to avoid issues
                if (!last_file)
                {
                    perror("ft_strdup");
                    free(r);
                    return -1;
                }
                i++;
            }
            red_tmp = red_tmp->next;
        }
        if (last_file)
            r[j++] = last_file;
        tmp = tmp->next;
    }
    r[j] = NULL;
    box->files = r;
    return 0;
}

void test(t_box *box)
{
    int fd[2];
    int prev_fd = -1;
    int i = 0, j = 0;

    if (run_all_heardocs2(box) != 0)
    {
        perror("run_all_heardocs");
        exit(1);
    }

    box->pid = malloc(sizeee(box) * sizeof(int));
    if (!box->pid)
    {
        perror("malloc");
        exit(1);
    }

    while (box->node->command)
    {
        if (box->node->command->next)
        {
            if (pipe(fd) == -1)
            {
                perror("pipe");
                exit(1);
            }
        }

        box->pid[j] = fork();
        if (box->pid[j] == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (box->pid[j] == 0)
        {
            ft_redirection(box, box->node->command->redirection, box->files[i], 1);

            if (box->input_file)
            {
                int Getfd_input__ = open(box->input_file, O_RDONLY);
                if (Getfd_input__ == -1 || dup2(Getfd_input__, 0) == -1)
                {
                    perror("input redirection");
                    exit(1);
                }
                close(Getfd_input__);
            }
            else if (prev_fd != -1)
            {
                if (dup2(prev_fd, 0) == -1)
                {
                    perror("prev_fd redirection");
                    exit(1);
                }
                close(prev_fd);
            }

            if (box->output_file)
            {
                int Getfd_output__;
                if (box->append)
                    Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
                else
                    Getfd_output__ = open(box->output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);

                if (Getfd_output__ == -1 || dup2(Getfd_output__, 1) == -1)
                {
                    perror("output redirection");
                    exit(1);
                }
                close(Getfd_output__);
            }
            else if (box->node->command->next)
            {
                if (dup2(fd[1], 1) == -1)
                {
                    perror("pipe redirection");
                    exit(1);
                }
                close(fd[1]);
            }

            // Execute the command
            if (put_builtins(box->node->command->options[0]))
            {
                builtins(box->node->command->options, box, 0);
                exit(0);
            }
            else
            {
                char **r = get_path__(box->env);
                char *full_path = fully(r, box->node->command->options[0]);
                if (!full_path || (ft_strncmp(box->node->command->options[0], "", -1) == 0))
                {
                    ft_putstr_fd("Command '", 2);
                    ft_putstr_fd(box->node->command->options[0], 2);
                    ft_putstr_fd("' not found\n", 2);
                    exit(127);
                }
                if (execve(full_path, box->node->command->options, box->full_env) == -1)
                {
                    perror("execve");
                    exit(1);
                }
            }
        }

        if (prev_fd != -1)
            close(prev_fd);
        if (box->node->command->next)
        {
            close(fd[1]);
            prev_fd = fd[0];
        }

        i++;
        j++;
        box->node->command = box->node->command->next;
    }

    while (wait(NULL) > 0) { }
}




