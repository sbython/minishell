
char	*ft___(char *file, int i)
{
	int pid  = fork();
	char	*new_file;
	char	*cpy_str_val;
	cpy_str_val = ft_strdup(file);
	new_file = random_file(cpy_str_val, i);
	if (pid == 0)
	{
		char	*promptt;
		int		fd;
		char	*line;

		promptt = "> ";
		fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		while ((line = readline(promptt)) != NULL)
		{
			if (ft_strncmp(line, file, ft_strlen(file)) == 0
				&& ft_strlen(file) == ft_strlen(line))
			{
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		exit(0);
	}
	int exitStatus = 0;
	wait(&exitStatus);
	return (new_file);
}

char **run_all_heardocs(t_box *box) 
{
    // int i = 0;
    // int j = 0;
	// int k = 0;
    // t_command *tmp = box->node->command;
	// // int status = 0;
    // char **files = (char **)malloc(sizeof(char *) * (how_her(box) + 1));
    // if (!files) 
	// {
    //     perror("malloc");
    //     return NULL;
    // }
    // while (tmp) 
	// {
    //     int pid = fork();
    //     if(pid == -1)
    //     {
    //         perror("fork failed");
    //         exit(0);
    //     }
    //     else if (pid == 0)
    //     {
	// 		// handlesignal(4, box);
	// 		t_redirection *red_tmp = tmp->redirection;
	// 		char *last_file = NULL;
	// 		while (red_tmp) 
	// 		{
	// 			if (red_tmp->flag == 4) 
	// 			{ 
	// 				if (last_file) 
	// 					free(last_file);
	// 				last_file = ft___(red_tmp->str, i);
	// 				if (!last_file) 
	// 				{
	// 					k = 0;
	// 					while (k < j) 
	// 					{
	// 						free(files[k]);
	// 						k++;
	// 					}
	// 					free(files);
	// 					return NULL;
	// 				}
	// 				i++;
	// 			}
	// 			red_tmp = red_tmp->next;
	// 		}
	// 		if (last_file) 
	// 			files[j++] = last_file;
	// 	}
	// 	else
	// 	{
	// 		wait(NULL);
	// 	}
	// 	j++;
	// 	tmp = tmp->next;
    // }
    // j = 0;

	
    // while (waitpid(box->pid[j++], &status, 0) > 0);
    // if (WIFSIGNALED(status))
    // {
    //     write(0, "\n", 1);
    //     box->exit_val = WTERMSIG(status) + 128;
    // }
    // else
    //     box->exit_val = WEXITSTATUS(status);
    // return box->exit_val;
    // files[j] = NULL;
    // return files;
	/*=====================================================*/
	t_command *tmpCommand = box->node->command;
	while (tmpCommand)
	{
		t_redirection *tmp = tmpCommand->redirection;
		int i = 0;
		while (tmp)
		{
			tmp->str = ft___(tmp->str, i++);
			tmp->flag = 2;
			tmp = tmp->next;
		}
		tmpCommand = tmpCommand->next;
	}
	char **str;
	str = NULL;
	return str;
}

