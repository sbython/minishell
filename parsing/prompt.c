/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:10:04 by msbai             #+#    #+#             */
/*   Updated: 2024/05/22 09:03:06 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char * gethost()
{
    int fd;
    char buffer[120];
    ssize_t i;
    char * hname;
    
    fd = open("/etc/hostname", O_RDONLY);
    if (fd == -1)
        return ft_strdup("X");
    i = read(fd, buffer, 120);
    if (i == -1)
    {
        close(fd);
        return "X";
    }
    buffer[i - 1] = 0;
    hname = ft_strdup(buffer);
    close(fd);
    return hname;
}
void join(char **dest, char * src, int i)
{
    char * tmp;

    tmp = ft_strjoin(*dest, src);
    free(*dest);
    if (i)
        free(src);
    *dest = tmp;
}
char *prompt()
{
    char *s;
    char tmp[1000];

    s = ft_strdup(GREENF);
    join(&s, getenv("LOGNAME"),0);
    join(&s, ft_strdup("@"),1);
    join(&s, gethost(),1);
    join(&s, ft_strdup(" "),1);
    getcwd(tmp, 1000);
    join(&s, tmp,0);
    join(&s, ft_strdup(":$ "),1);
    join(&s, ft_strdup(DCOLORF),1);
    return(s);
}

