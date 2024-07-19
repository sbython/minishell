/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vvv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:06:12 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/18 09:14:54 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct command {
    char **options;  // Command and arguments array
    char *input_file; // For '<' and '<<'
    char *output_file; // For '>' and '>>'
    int append; // 1 for '>>', 0 for '>'
    struct command *next;
} t_command1;

typedef struct node {
    t_command1 *command;
} t_node1;

typedef struct {
    t_node *node;
} t_box1;


int main() {
    // Example usage:
    char *cmd1_args[] = {"ls", "-l", NULL};
    char *cmd2_args[] = {"cat", "-e", NULL};
    char *cmd3_args[] = {"free", "-k", NULL};
    
    t_command1 cmd1 = {cmd1_args, NULL, NULL, 0, NULL};
    t_command1 cmd2 = {cmd2_args, NULL, NULL, 0, NULL};
    t_command1 cmd3 = {cmd3_args, NULL, NULL, 0, NULL};
    
    cmd1.next = &cmd2;
    cmd2.next = &cmd3;
    
    t_node1 node = {&cmd1};
    t_box1 box = {&node};
    
    execute(&box);
    
    return 0;
}
