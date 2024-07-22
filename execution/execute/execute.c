/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 06:42:03 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ex___type___2(char *file)
{
    // (void)file;
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
    // if (fd == -1) 
    // {
    //     perror("open");
    //     exit(0);
    // }
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

// // void ex___type___5(char *file)
// // {
// //     // (void)file;
// //     // int f___dType_5;
    
// //     // f___dType_5 = open(file, O_WRONLY | O_CREAT, 0666);
// //     // if(f___dType_5 == -1)
// //     // {
// //     //     perror(file);
// //     //     exit(0);
// //     // }
// //     printf("file: %s\n", file);
// // }

void f__redirection(t_box *box, t_redirection *redirection)
{
    (void)box;
    char *file_input = NULL;
    char *file_output = NULL;
    int check_heardoc_val = check_heardoc(redirection);
    box->append = 0;

    box->done_heardoc = 1;
    t_redirection* tmp_redirection = redirection;
    if(check_heardoc_val)
    {
        while (tmp_redirection)
        {
            // if(tmp_redirection->flag == 4)
            // {
            //     // file_output = tmp_redirection->str;
            //     box->sp___file_input = ex___type___4(box, tmp_redirection->str);
                
            //     check_heardoc_val = 0;
            //     // f__redirection(box, redirection);
            // }
            // tmp_redirection = tmp_redirection->next;
        if (tmp_redirection->flag == 4) // Heredoc
        {
            int heredoc_fd[2];
            if (pipe(heredoc_fd) == -1)
            {
                perror("pipe");
                exit(EXIT_FAILURE);
            }

            pid_t heredoc_pid = fork();
            if (heredoc_pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (heredoc_pid == 0)
            {
                
                close(heredoc_fd[0]);
                write(heredoc_fd[1], tmp_redirection->str, ft_strlen(tmp_redirection->str)); // Write heredoc content
                close(heredoc_fd[1]);
                exit(EXIT_SUCCESS);
            }
            else
            {
                
                close(heredoc_fd[1]);
                box->input_file = NULL;
                dup2(heredoc_fd[0], 0);
                close(heredoc_fd[0]);
                wait(NULL); 
            }
        }
        tmp_redirection = tmp_redirection->next;
        }
    }

    // printf("sp___file_input: %s\n", box->sp___file_input);
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

            else if(redirection->flag == 4)
            {
                file_input = box->sp___file_input;
                // printf("file_input: %s\n", file_input);
                // ex___type___3(file_output);
            }
            else if(redirection->flag == 5)
            {
                file_output = redirection->str;
                // printf("%s\n", file_output);
                // ex___type___5(file_output);
                box->append = 100;
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
            if(box->input_file)
            {
                int Get_i___File = open(box->input_file, O_RDONLY, 0666);
                if (dup2(Get_i___File, 0) == -1) 
                {
                    perror("dup2 1");
                    close(Get_i___File);
                    exit(0);
                }
            }
            if(box->output_file)
            {
                int Get_o___File;
                if(box->append == 100)
                    Get_o___File = open(box->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
                else
                    Get_o___File = open(box->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);;
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
// // ls < c << cc > x >> xx

// // void f__redirection(t_box *box, t_redirection *redirections)
// // {
// //     // Handle redirections including heredoc
// //     t_redirection *redir = redirections;

// //     while (redir)
// //     {
        
// //         // Handle other redirections (input, output, append)
// //         else if (redir->type == 2) // Input redirection
// //         {
// //             box->input_file = redir->file_name;
// //         }
// //         else if (redir->type == 3) // Output redirection
// //         {
// //             box->output_file = redir->file_name;
// //             box->append = 0;
// //         }
// //         else if (redir->type == 5) // Append redirection
// //         {
// //             box->output_file = redir->file_name;
// //             box->append = 100;
// //         }
// //         redir = redir->next;
// //     }
// // }


// void execute(t_box *box)
// {
//     int fd[2];
//     int prev_fd = -1;
//     pid_t pid;
//     char **r = get_path__(box->env);
//     t_command *current_command = box->node->command;

//     while (current_command)
//     {
//         if (pipe(fd) == -1)
//         {
//             perror("pipe");
//             exit(EXIT_FAILURE);
//         }

//         pid = fork();

//         if (pid == -1)
//         {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }
//         else if (pid == 0)
//         {
//             if (prev_fd != -1)
//             {
//                 if (dup2(prev_fd, 0) == -1)
//                 {
//                     perror("dup2 prev_fd");
//                     close(prev_fd);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(prev_fd);
//             }

//             if (current_command->next != NULL)
//             {
//                 close(fd[0]);
//                 if (dup2(fd[1], 1) == -1)
//                 {
//                     perror("dup2 fd[1]");
//                     close(fd[1]);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(fd[1]);
//             }

//             f__redirection(box, current_command->redirection);

//             if (box->input_file)
//             {
//                 int Get_i___File = open(box->input_file, O_RDONLY, 0666);
//                 if (dup2(Get_i___File, 0) == -1)
//                 {
//                     perror("dup2 input_file");
//                     close(Get_i___File);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(Get_i___File);
//             }

//             if (box->output_file)
//             {
//                 int Get_o___File;
//                 if (box->append == 100)
//                     Get_o___File = open(box->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
//                 else
//                     Get_o___File = open(box->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                
//                 if (dup2(Get_o___File, 1) == -1)
//                 {
//                     perror("dup2 output_file");
//                     close(Get_o___File);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(Get_o___File);
//             }

//             char *full_path = fully(r, current_command->options[0]);
//             if (execve(full_path, current_command->options, box->full_env) == -1)
//             {
//                 perror("execve");
//                 exit(EXIT_FAILURE);
//             }
//             exit(EXIT_SUCCESS);
//         }
//         else
//         {
//             close(fd[1]);
//             if (prev_fd != -1)
//                 close(prev_fd);

//             prev_fd = fd[0];

//             current_command = current_command->next;
//         }
//     }

//     if (prev_fd != -1)
//         close(prev_fd);

//     while (wait(NULL) > 0);
// }

// char* ex___type___4(t_box *box, char *file, int pipe_fd)
// {
//     (void)box;
//     box->done_heardoc = 0;
//     char*cpy_str_val = ft_strdup(file);
//     // char*r = random_file(cpy_str_val);
//     char *promptt = "> ";
//     char *line;

//     while ((line = readline(promptt)) != NULL)
//     {
//         if (ft_strncmp(line, file, ft_strlen(file)) == 0 && ft_strlen(file) == ft_strlen(line))
//         {
//             break;
//         }
//         write(pipe_fd, line, ft_strlen(line));
//         write(pipe_fd, "\n", 1);
//     }
//     free(line);
//     close(pipe_fd);
//     return cpy_str_val;
// }


// void f__redirection(t_box *box, t_redirection *redirection)
// {
//     (void)box;
//     char *file_input = NULL;
//     char *file_output = NULL;
//     int check_heardoc_val = check_heardoc(redirection);
//     box->append = 0;

//     box->done_heardoc = 1;
//     t_redirection* tmp_redirection = redirection;
//     if(check_heardoc_val)
//     {
//         while (tmp_redirection)
//         {
//             if (tmp_redirection->flag == 4) // Heredoc
//             {
//                 int heredoc_fd[2];
//                 if (pipe(heredoc_fd) == -1)
//                 {
//                     perror("pipe");
//                     exit(EXIT_FAILURE);
//                 }

//                 pid_t heredoc_pid = fork();
//                 if (heredoc_pid == -1)
//                 {
//                     perror("fork");
//                     exit(EXIT_FAILURE);
//                 }
//                 else if (heredoc_pid == 0)
//                 {
//                     close(heredoc_fd[0]);
//                     ex___type___4(box, tmp_redirection->str, heredoc_fd[1]);
//                     exit(EXIT_SUCCESS);
//                 }
//                 else
//                 {
//                     close(heredoc_fd[1]);
//                     box->input_file = NULL;
//                     dup2(heredoc_fd[0], 0);
//                     close(heredoc_fd[0]);
//                     wait(NULL); 
//                 }
//             }
//             tmp_redirection = tmp_redirection->next;
//         }
//     }

//     if(!check_heardoc_val)
//     {
//         while (redirection)
//         {
//             if(redirection->flag == 2)
//             {
//                 file_input = redirection->str;
//                 ex___type___2(file_input);
//             }
//             else if(redirection->flag == 3)
//             {
//                 file_output = redirection->str;
//                 ex___type___3(file_output);
//             }

//             else if(redirection->flag == 4)
//             {
//                 file_input = box->sp___file_input;
//             }
//             else if(redirection->flag == 5)
//             {
//                 file_output = redirection->str;
//                 box->append = 100;
//             }
//             redirection = redirection->next;
//         }
//     }
//     box->input_file = file_input;
//     box->output_file = file_output;
// }


// void execute(t_box *box)
// {
//     int fd[2];
//     int prev_fd = -1;
//     pid_t pid;
//     char **r = get_path__(box->env);
//     t_command *current_command = box->node->command;

//     while (current_command)
//     {
//         if (pipe(fd) == -1)
//         {
//             perror("pipe");
//             exit(EXIT_FAILURE);
//         }

//         pid = fork();

//         if (pid == -1)
//         {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }
//         else if (pid == 0)
//         {
//             if (prev_fd != -1)
//             {
//                 if (dup2(prev_fd, 0) == -1)
//                 {
//                     perror("dup2 prev_fd");
//                     close(prev_fd);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(prev_fd);
//             }

//             if (current_command->next != NULL)
//             {
//                 close(fd[0]);
//                 if (dup2(fd[1], 1) == -1)
//                 {
//                     perror("dup2 fd[1]");
//                     close(fd[1]);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(fd[1]);
//             }

//             f__redirection(box, current_command->redirection);

//             if (box->input_file)
//             {
//                 int Get_i___File = open(box->input_file, O_RDONLY, 0666);
//                 if (dup2(Get_i___File, 0) == -1)
//                 {
//                     perror("dup2 input_file");
//                     close(Get_i___File);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(Get_i___File);
//             }

//             if (box->output_file)
//             {
//                 int Get_o___File;
//                 if (box->append == 100)
//                     Get_o___File = open(box->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
//                 else
//                     Get_o___File = open(box->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                
//                 if (dup2(Get_o___File, 1) == -1)
//                 {
//                     perror("dup2 output_file");
//                     close(Get_o___File);
//                     exit(EXIT_FAILURE);
//                 }
//                 close(Get_o___File);
//             }

//             char *full_path = fully(r, current_command->options[0]);
//             if (execve(full_path, current_command->options, box->full_env) == -1)
//             {
//                 perror("execve");
//                 exit(EXIT_FAILURE);
//             }
//             exit(EXIT_SUCCESS);
//         }
//         else
//         {
//             close(fd[1]);
//             if (prev_fd != -1)
//                 close(prev_fd);

//             prev_fd = fd[0];

//             current_command = current_command->next;
//         }
//     }

//     if (prev_fd != -1)
//         close(prev_fd);

//     while (wait(NULL) > 0);
// }
