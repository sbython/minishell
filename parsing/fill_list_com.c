
#include "../minishell.h"

t_com  * new_node(char *str)
{
    t_com *node;

    node = malloc(sizeof(t_com));
    node->com = str;
    node->next = NULL;
     node->prev = NULL;
    return node;
}
t_com *last_node(t_com *node)
{
    if(!node)
        return NULL;
    while (node->next)
        node = node->next;
    return(node);
}

void pop(t_com ** node, t_com *new)
{
    t_com *last;
    if (!*node)
    {
        *node = new;
        return ;
    }
    last = last_node(*node);
    last->next = new;
    new->prev = last;
}

void    fill_list(char **ptr, t_box *box)
{
    int i;
    char *str;
    t_com * node;
    i = 0;
    node = NULL;

    while (ptr[i])
    {
        str = ft_strdup(ptr[i]);
        pop(&node,new_node(str));
        i++;
    }
    box->l_com = node;
}
