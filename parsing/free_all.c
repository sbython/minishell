
#include "../minishell.h"

void  free_env(env *lst)
{
    env *tmp;

    while (lst)
    {
        free(lst->name);
        // free(lst->vale);
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    
}


void  free_all(t_box *box)
{
    free_env(box->env);

}