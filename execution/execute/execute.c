/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:43:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/22 14:25:44 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ex___type___2(char *file)
{
	int	f___dType_2;

	// (void)file;
	f___dType_2 = open(file, O_RDONLY, 0666);
	if (f___dType_2 == -1)
	{
		perror(file);
		exit(0);
	}
}

void	ex___type___3(char *file)
{
	int	f___dType_2;

	f___dType_2 = open(file, O_WRONLY | O_CREAT, 0666);
	if (f___dType_2 == -1)
	{
		perror(file);
		exit(0);
	}
}

char	*ex___type___4(t_box *box, char *file)
{
	char	*cpy_str_val;
	char	*new_file;
	char	*promptt;
	int		fd;
	char	*line;

	(void)box;
	box->done_heardoc = 0;
	cpy_str_val = ft_strdup(file);
	new_file = random_file(cpy_str_val);
	promptt = "> ";
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
		if (ft_strncmp(line, file, ft_strlen(file)) == 0
			&& ft_strlen(file) == ft_strlen(line))
		{
			// box->done_heardoc = 0;
			break ;
		}
	}
	return (new_file);
}

// void ex___type___5(char *file)
// {
//     // (void)file;
//     // int f___dType_5;

//     // f___dType_5 = open(file, O_WRONLY | O_CREAT, 0666);
//     // if(f___dType_5 == -1)
//     // {
//     //     perror(file);
//     //     exit(0);
//     // }
//     printf("file: %s\n", file);
// }

void	f__redirection(t_box *box, t_redirection *redirection)
{
	char			*file_input;
	char			*file_output;
	int				check_heardoc_val;
	t_redirection	*tmp_redirection;

	(void)box;
	file_input = NULL;
	file_output = NULL;
	check_heardoc_val = check_heardoc(redirection);
	box->append = 0;
	box->done_heardoc = 1;
	tmp_redirection = redirection;
	if (check_heardoc_val)
	{
		while (tmp_redirection)
		{
			if (tmp_redirection->flag == 4)
			{
				// printf("%s\n", tmp_redirection->str);
				box->sp___file_input = ex___type___4(box,
						tmp_redirection->str);
				check_heardoc_val = 0;
			}
			tmp_redirection = tmp_redirection->next;
		}
	}
	if (!check_heardoc_val)
	{
		while (redirection)
		{
			if (redirection->flag == 2)
			{
				file_input = redirection->str;
				ex___type___2(file_input);
			}
			else if (redirection->flag == 3)
			{
				file_output = redirection->str;
				ex___type___3(file_output);
			}
			else if (redirection->flag == 4)
			{
				file_input = box->sp___file_input;
				// printf("file_input: %s\n", file_input);
				// ex___type___3(file_output);
			}
			else if (redirection->flag == 5)
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

void	execute(t_box *box)
{
	int		fd[2];
	int		prev_fd;
	pid_t	pid;
	char	**r;
	int		Get_i___File;
	int		Get_o___File;
	char	*full_path;

	(void)box;
	prev_fd = -1;
	r = get_path__(box->env);
	printf("HAAAAAAAAAALA\n");
	// while (box->node->command)
	// {
	// 	while(box->node->command->redirection)
	// 	{
	// 		printf("str: %s\n", box->node->command->redirection->str);
	// 		box->node->command->redirection = box->node->command->redirection->next;
	// 	}
	// 	box->node->command = box->node->command->next;
	// }

	box->done_heardoc = 0;
	if(!box->done_heardoc)
	     heardoc___s(box);
	if (box->done_heardoc)
	{
		// //*** */ 
		// int i = 0;
		// while (i < 10000)
		// {
		// 	printf("execution");
		// 	i++;
		// }
		
		// ** */ ***/
		while (box->node->command)
		{
			if (pipe(fd) == -1)
			{
				perror("pipe");
				exit(1);
			}
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(1);
			}
			else if (pid == 0)
			{
				if (prev_fd != -1)
				{
					if (dup2(prev_fd, 0) == -1)
					{
						perror("dup2 prev_fd");
						close(prev_fd);
						exit(1);
					}
					close(prev_fd);
				}
				if (box->node->command->next != NULL)
				{
					close(fd[0]);
					if (dup2(fd[1], 1) == -1)
					{
						perror("dup2 fd[1]");
						close(fd[1]);
						exit(1);
					}
					close(fd[1]);
				}
				f__redirection(box, box->node->command->redirection);
				if (box->input_file)
				{
					Get_i___File = open(box->input_file, O_RDONLY);
					if (Get_i___File == -1)
					{
						perror("open input_file");
						exit(1);
					}
					if (dup2(Get_i___File, 0) == -1)
					{
						perror("dup2 input_file");
						close(Get_i___File);
						exit(1);
					}
					close(Get_i___File);
				}
				if (box->output_file)
				{
					if (box->append == 100)
						Get_o___File = open(box->output_file,
								O_WRONLY | O_CREAT | O_APPEND, 0644);
					else
						Get_o___File = open(box->output_file,
								O_WRONLY | O_CREAT | O_TRUNC, 0644);
					if (Get_o___File == -1)
					{
						perror("open output_file");
						exit(1);
					}
					if (dup2(Get_o___File, 1) == -1)
					{
						perror("dup2 output_file");
						close(Get_o___File);
						exit(1);
					}
					close(Get_o___File);
				}
				full_path = fully(r, box->node->command->options[0]);
				if (execve(full_path, box->node->command->options,
						box->full_env) == -1)
				{
					perror("execve");
					exit(1);
				}
				exit(0);
			}
			else
			{
				close(fd[1]);
				if (prev_fd != -1)
					close(prev_fd);
				prev_fd = fd[0];
				box->node->command = box->node->command->next;
			}
		}
		if (prev_fd != -1)
			close(prev_fd);
		while (wait(NULL) > 0)
			;
	}
}
