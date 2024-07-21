/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/21 18:38:24 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ex___type___2(char *file)
{
    int f___dType_2;
    
    f___dType_2 = open(file, O_RDONLY, 0666);
    if(f___dType_2 == -1)
    {
        perror(file);
        exit(0);
    }
}

void ex___type___3(char *file)
{
    int f___dType_2;
    
    f___dType_2 = open(file, O_WRONLY | O_CREAT, 0666);
    if(f___dType_2 == -1)
    {
        perror(file);
        exit(0);
    }
}

char* ex___type___4(t_box *box, char *file)
{
    (void)box;
    box->done_heardoc = 0;
    char*cpy_str_val = ft_strdup(file);
    char*new_file = random_file(cpy_str_val);
    char *promptt = "> ";
    int fd;
    char *line;
    fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) 
    {
        perror("open");
        exit(0);
    }
    while ((line = readline(promptt)) != NULL)
    {
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        if(ft_strncmp(line, file, ft_strlen(file)) == 0 
        && ft_strlen(file) == ft_strlen(line))
        {
            // box->done_heardoc = 0;
            break;
        }
    }
    return new_file;
}

void ex___type___5(char *file)
{
    // (void)file;
    // int f___dType_5;
    
    // f___dType_5 = open(file, O_WRONLY | O_CREAT, 0666);
    // if(f___dType_5 == -1)
    // {
    //     perror(file);
    //     exit(0);
    // }
    printf("file: %s\n", file);
}

void f__redirection(t_box *box, t_redirection *redirection)
{
    (void)box;
    char *file_input = NULL;
    char *file_output = NULL;
    int check_heardoc_val = check_heardoc(redirection);

    // box->done_heardoc = 1;
    t_redirection* tmp_redirection = redirection;
    if(check_heardoc_val)
    {
        while (tmp_redirection)
        {
            if(tmp_redirection->flag == 4)
            {
                ex___type___4(box, tmp_redirection->str);
                check_heardoc_val = 0;
                // f__redirection(box, redirection);
            }
            tmp_redirection = tmp_redirection->next;
        }
    }

    if(!check_heardoc_val)
    {
        while (redirection)
        {
            if(redirection->flag == 2)
            {
                file_input = redirection->str;
                ex___type___2(file_input);
            }
            else if(redirection->flag == 3)
            {
                file_output = redirection->str;
                ex___type___3(file_output);
            }
            else if(redirection->flag == 5)
            {
                file_output = redirection->str;
                // printf("%s\n", file_output);
                ex___type___5(file_output);
            }
            // printf("redirection->str: %s\n", redirection->str);
            // printf("redirection->flag: %d\n", redirection->flag);
            redirection = redirection->next;
        }
    }
    box->input_file = file_input;
    box->output_file = file_output;
}

void execute(t_box *box)
{
    int pid = fork();
    char** r = get_path__(box->env);
    while (box->node->command)
    {
        if(pid == -1)
        {
            perror("EXIT");
            exit(0);
        }
        else if(pid == 0)
        {
            f__redirection(box, box->node->command->redirection);
            // printf("box->input_file: %s\n", box->input_file);
            // printf("box->output_file: %s\n", box->output_file);

            if(box->input_file)
            {
                // printf("box->input_file: %s\n", box->input_file);
                int Get_i___File = open(box->input_file, O_RDONLY, 0666);
                if(Get_i___File == -1)
                {
                    perror(box->input_file);
                    exit(0);
                }
                if (dup2(Get_i___File, 0) == -1) 
                {
                    perror("dup2 1");
                    close(Get_i___File);
                    exit(0);
                }
            }
            if(box->output_file)
            {
                int Get_o___File = open(box->output_file, O_WRONLY | O_CREAT, 0644);;
                if (dup2(Get_o___File, 1) == -1) 
                {
                    perror("dup2 2");
                    close(Get_o___File);
                    exit(0);
                }
            }
            char *full_path = fully(r, box->node->command->options[0]);
            if((execve(full_path, box->node->command->options, box->full_env) == -1))
            {
                perror("not found");
                exit(0);
            }
            exit(0);
        }
        box->node->command = box->node->command->next;
    }
    while (wait(NULL) > 0);
}
