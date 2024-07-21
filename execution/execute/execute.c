/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/21 15:36:54 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// // void execute(t_box *box)
// // {
// //     (void)box;
// //     t_command *current_command = box->node->command;
// //     int pipe_fd[2];

// //     int prev_pipe_read = -1;
// //     char** r = get_path__(box->env);

// //     while (current_command)
// //     {
// //         if (pipe(pipe_fd) == -1)
// //         {
// //             perror("error");
// //             exit(0);
// //         }

// //         pid_t pid = fork();
// //         if (pid == -1)
// //         {
// //             perror("fork failed");
// //             exit(0);
// //         }
// //         else if (pid == 0)
// //         {
// //             if (prev_pipe_read != -1)
// //             {
// //                 dup2(prev_pipe_read, 0);
// //                 close(prev_pipe_read);
// //             }

// //             if (current_command->next != NULL)
// //                 dup2(pipe_fd[1], 1);

// //             close(pipe_fd[0]);

// //             char *full_path = fully(r, current_command->options[0]);
// //             if((execve(full_path, current_command->options, box->full_env) == -1))
// //             {
// //                 // printf("Command '%s'", current_command->options[0]);
// //                 // printf("%s", " not found\n");
// //                 ft_putstr_fd("file not found\n", 2);
// //                 exit(0);
// //             }
// //             perror("execve failed");
// //             exit(0);
// //         }
// //         else
// //         {
// //             if (prev_pipe_read != -1)
// //                 close(prev_pipe_read);

// //             close(pipe_fd[1]);
// //             prev_pipe_read = pipe_fd[0];

// //             current_command = current_command->next;
// //         }
// //     }
// //     close(prev_pipe_read);
// //     while (wait(NULL) > 0);
// // }

// // void last_file(t_command *command)
// // {
// //     // printf("first: %s    %d\n", command->redirection->str, command->redirection->flag);
// //     // printf("second: %s    %d\n", command->redirection->next->str, command->redirection->next->flag);
// //     // char *end_file;
// //     // int count = 0;

// //     while (command)
// //     {
// //         printf("str: %s ", command->redirection->str);
// //         printf("         flag: %d\n", command->redirection->flag);
// //         // if(command->redirection->next->flag != 2)
// //         // {
// //             // end_file = command->redirection->str;
// //             // printf("next str: %s\n", command->redirection->next->str);
// //             // count++;
// //         // }
// //         command = command->next;
// //     }
// //     // printf("count %d\n", count);
// //     // return ;
// // }

// // void    last_file()
// // {
// //     char *end_file;
    
// //     // printf("%s\n", end_file);
// // }

// void   f_redirection(t_redirection *redirection)
// {
//     char *end_file;
//     while (redirection)
//     {
//         if(redirection->flag == 2)
//             end_file = redirection->str;
//         redirection = redirection->next;
//     }
//     printf("%s\n", end_file);
// }

// void f(t_command *cmd)
// {
//     int i = 0;
//     while (cmd->options[i])
//     {
//         printf("%s\n", cmd->options[i]);
//         i++;
//     }
// }

// char*    one_column(t_redirection *redirection, int flag)
// {
//     char *end_file_typex = NULL;
//     while (redirection)
//     {
//         if(redirection->flag == flag)
//             end_file_typex = redirection->str;
//         redirection = redirection->next;
//     }
//     return end_file_typex;
// }

// int ex___type___2(t_redirection *redirection)
// {
//     // char *end_File = one_column(redirection, 2);
//     // printf("end_File: %s\n", end_File);

//     int fd;
//     int check;

//     check = 1;
//     while (redirection)
//     {
//         fd = open(redirection->str, O_RDONLY, 0666);
//         if(fd == -1)
//         {
//             check = 0;
//             perror(redirection->str);
//             exit(0);
//         }
//         redirection = redirection->next;
//     }
//     return check;
// }

// void ex___type___3(t_redirection *redirection)
// {
//     int fd;
//     fd = open(redirection->str, O_CREAT | O_WRONLY, 0666);
//     // printf("file: %s\n", redirection->str);
//     if(write(fd, "file name", 9) == -1)
//     {
//         perror("can't write");
//         exit(0);
//     }
// }

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

void ex___type___4(char *file)
{
    char *promptt = "> ";
    int fd;
    char *line;
    // char *tmp___col = ft_strjoin("/tmp/", file);
    // printf("%s\n", tmp___col);
    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // fd = open(tmp___col, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }
    while ((line = readline(promptt)) != NULL)
    {
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        if(ft_strncmp(line, file, ft_strlen(file)) == 0)
        {
            break;
        }
    }
}

void ex___type___5(char *file)
{
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
    // int check_heardoc_val = check_heardoc(redirection);
    char *file_input = NULL;
    char *file_output = NULL;
    // if(check_heardoc_val)
    // {
    //     // ex___type___4();
    //     return ;
    // }
    // else
    // {
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
            else if(redirection->flag == 4)
            {
                file_input = redirection->str;
                ex___type___4(file_input);
            }
            else if(redirection->flag == 5)
            {
                file_output = redirection->str;
                ex___type___5(file_output);
            }
            redirection = redirection->next;
        }
    // }
    box->input_file = file_input;
    box->output_file = file_output;
    
    // printf("before box->input_file: %s\n", box->input_file);
    // printf("before box->output_file: %s\n", box->output_file);
}

void execute(t_box *box)
{
    // t_box *command = box->node->command;
    // f(box->node->command);
    // one_column(box->node->command->redirection);
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
            

            if(box->input_file)
            {
                // printf("box->input_file: %s\n", box->input_file);
                // int Get_i___File = open(box->input_file, O_RDONLY, 0666);
                // printf("%s\n", box->input_file);
                int Get_i___File = open(box->input_file, O_RDONLY, 0666);
                // if(Get_i___File == -1)
                // {
                //     perror(box->input_file);
                //     exit(0);
                // }
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
