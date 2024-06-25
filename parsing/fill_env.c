

#include "../minishell.h"
env * add_new_var(char *name , char * vale)
{
    env * lst;

    lst = malloc(sizeof(env));
    if (!lst)
        return NULL;    
    lst->name = name;
    lst->vale = vale;
    lst->next = NULL;
    return lst;
}

env *last_n(env *node)
{
    if(!node)
        return NULL;
    while (node->next)
    {
        node = node->next;
    }
    return(node);
}

void add_back(env **node, env *new)
{

    env *last;
    if (!*node)
    {
        *node = new;
        return ;
    }
    last = last_n(*node);
    last->next = new;
}
env * fill_env(char **en)
{
    int i;
    env * lst;
    char *name;
    char *vale;
    char * new;
    i = 0;
    lst = NULL;
    while (en[i])
    {
        new = ft_strdup(en[i]);

        name = new;
        vale = ft_strchr(new, '=');
        *vale = 0;
        vale++;
        add_back(&lst, add_new_var(name,vale));
        i++;
    }
    return lst;
}