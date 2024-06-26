
#include "../minishell.h"

int check_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == '"')
        {
            str = ft_strchr(str + (i + 1), '"');
            if (!str)
                return (1);
            i = 0;
        }
        else if(str[i] == '\'')
        {
            str = ft_strchr(str + (i + 1), '\'');
            if (!str)
                return (1);
            i = 0;
        }
        i++;
        
    }
    return (0);
}
void join_node(t_com *com)
{
    t_com *ne;
    t_com *ne_ne;

    if (!com->next)
        printf("need a \" in the end of : %s\n", com->com),exit(1);
    ne = com->next;
    ne_ne = ne->next;

    join(&(com->com), " ", 0);
    join(&(com->com), ne->com, 1);
    com->next = ne_ne;
    if(ne_ne)
        ne_ne->prev = com;

    free(ne);
}
void collect_string(t_box *box)
{
    t_com *ls;
    ls = box->l_com;
    while (ls)
    {
        if (check_str(ls->com))
            join_node(ls);
        else
            ls = ls->next;
        
    }
}
