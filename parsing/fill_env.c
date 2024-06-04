

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
void add_front(env **lst, env *new)
{

    new->next = *lst;
    *lst = new;
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
        add_front(&lst, add_new_var(name,vale));
        // printf("%s-- %s -- %s\n", lst->name, lst->vale, new);
        i++;
    }
    return lst;
}