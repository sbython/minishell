/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:10:40 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/07/09 00:11:19 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int len_to(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c && str[i] != '\'' && str[i] != '"') 
    { 
        i++;
        if (str[i] == '$' || str[i] == '?')
        {
            i++;
            break;
        }
    }
    return (i);
}
char *get_to(char *str, char c)
{
    char *p;
    int len;

    len = len_to(str, c);
    p = malloc((len + 1) * sizeof(char));
    if(!p)
        return (NULL);
    ft_memcpy(p, str, len);
    p[len] = '\0';
    return (p);
}
char * get_val(char *str1 , env * en, t_box *box)
{
    char *str;

     if (!ft_strncmp(str1, "$", 2))
        return(ft_strdup(box->getpid));
    else if (!ft_strncmp(str1, "?", 2))
        return(ft_itoa(box->exit_val));
    str = ft_strtrim(str1, "\"'");
    if (!*str)
        return (free(str),ft_strdup("$"));
    while (en)
    {
        if(!ft_strncmp(str, en->name, ft_strlen(str)))
            return (free(str),ft_strdup(en->vale));
        en = en->next;
    }
    free(str);
    return ft_strdup("");
}
// ptr[0] it is a return string 
// ptr[1] it name of variable 
// ptr[2] it is left string after take a ptr[1] or ptr [0]
char *replace(char *str , env * en,t_box *box)
{
    char *ptr[4];
    char *tmp;

    tmp = str;
    ptr[2] = str;
    while ((ptr[2] =  ft_strchr(ptr[2], '$')))
    {
        ptr[1] = get_to(ptr[2], ' ');
        ptr[0] = get_val(ptr[1] + 1, en, box);
        str = str_replace(str, ptr[1] , ptr[0]);
        free(ptr[1]);
        free(ptr[0]);
        ptr[2] =  ft_strchr(ptr[2] + 1 , ' ');
        if (!ptr[2])
        {  
            free(tmp);
            return (str);
        }
    }
    free(tmp);
    return (str);
}

void replace_var(t_box *box)
{
    t_com *com;

    com = box->l_com;
    while (com)
    {
        if (ft_strchr(com->com, '$'))
        {
            
                com->com = replace(com->com, box->env, box);
            // printf(com->com);
        }
        else if(com->com[0] == '~' && com->com[1] == 0)
                com->com =  str_replace(com->com, "~", getenv("HOME"));
        com = com->next;
    }
}