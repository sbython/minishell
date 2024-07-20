/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/20 15:35:50 by zibnoukh         ###   ########.fr       */
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

void f__redirection(t_box *box, t_redirection *redirection)
{
    (void)box;
    int check_heardoc_val = check_heardoc(redirection);
    char *endfile_flag2 = NULL;
    char *endfile_flag3 = NULL;
    if(check_heardoc_val)
    {
        // printf("%s\n", "there is");
        char *line;
        while ((line = readline("> ")) != NULL)
        {
            if(ft_strncmp(line, "line", 4) == 0)
            {
                check_heardoc_val = 0;
                break;
            }
        }
    }
    else
    {
        while (redirection)
        {
            if(redirection->flag == 2)
            {
                ex___type___2(redirection->str);
                endfile_flag2 = redirection->str;
            }
            else if(redirection->flag == 3)
            {
                ex___type___3(redirection->str);
                endfile_flag3 = redirection->str;
            }
            redirection = redirection->next;
        }
    }
    box->input_file = endfile_flag2;
    box->output_file = endfile_flag3;
}

void execute(t_box *box)
{
    // t_box *command = box->node->command;
    // f(box->node->command);
    // one_column(box->node->command->redirection);
    int pid = fork();
    // char** r = get_path__(box->env);
    // int ex___;
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
            // printf("box->input_file: %s\n", box->output_file);
            // printf("box->input_file: %s\n", box->input_file);
            // printf("box->output_file: %s\n", box->output_file);
            int get_____f_dinput_file = open(box->output_file, O_WRONLY | O_CREAT, 0666);
            // if( dup2(get_____f_dinput_file, 1))
            if(dup2(get_____f_dinput_file, 1) == -1)
            {
                perror("dup2 fail");
                exit(0);
            }
            // char *full_path = fully(r, box->node->command->options[0]);
            // if((execve(full_path, box->node->command->options, box->full_env) == -1))
            // {
            //     perror("not found");
            //     exit(0);
            // }
            exit(0);
        }
        box->node->command = box->node->command->next;
    }
    while (wait(NULL) > 0);
}
