/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc___s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 10:11:19 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void    max_here_document(int count)
// {
//     if(count >= 16)
//     {
//         printf("maximum here-document count exceeded");
//         exit(0);
//     }
// }

// int check_one()
// {
//     printf("%d\n", 0 + 1);
//     return 1;
// }

// void run___heardoc(t_box*box, char *file)
// {
//     (void)box;
//     // box->node->command->redirection->close_heardoc = 0;
//     char*cpy_str_val = ft_strdup(file);
//     char*new_file = random_file(cpy_str_val);
//     char *promptt = "> ";
//     int fd;
//     char *line;
//     // int check = 0;
//     fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
//     // if (fd == -1) 
//     // {
//     //     perror("open");
//     //     exit(0);
//     // }
//     while ((line = readline(promptt)) != NULL)
//     {
//         write(fd, line, ft_strlen(line));
//         write(fd, "\n", 1);
//         if(ft_strncmp(line, file, ft_strlen(file)) == 0 
//         && ft_strlen(file) == ft_strlen(line))
//         {
//             // check = 1;
//             break;
//         }
//     }
//     // if(check)
//     //     return 1;
//     // else
//     //     return 0;
//     // printf("box->nodedirection-se_heardoc: %d\n", box->node->command->redirection->close_heardoc);
//     // return new_file;
// }

// void search_all(t_box* box)
// {
//     (void)box;
//     // int max_here_document_val = 0;
//     // int close_c = 0;
//     while (box->node->command)
//     {
//         while (box->node->command->redirection)
//         {
//             if(box->node->command->redirection->flag == 4)
//             {
//                 // if(run___heardoc(box, box->node->command->redirection->str))
//                 // {
//                 //     // printf("%s\n", "is run___heardoc");
//                 //     close_c++;
//                 // }
//                 // max_here_document_val++;
//                 run___heardoc(box, box->node->command->redirection->str);
//             }
//             box->node->command->redirection = box->node->command->redirection->next;
//         }
//         box->node->command = box->node->command->next;
//     }
    
//     // box->node->command->redirection->close_heardoc = close_c ;
//     // return max_here_document_val;
// }

void    search_all(t_box *box)
{
    while (box->node->command)
    {
        while (box->node->command->redirection)
        {
            printf("str: %s\n", box->node->command->redirection->str);
            printf("flag: %d\n", box->node->command->redirection->flag);
            box->node->command->redirection = box->node->command->redirection->next;
        }
        box->node->command = box->node->command->next;
    }
}

void    heardoc___s(t_box *box)
{
    (void)box;
    search_all(box);
}
