
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
void  free_lcom(t_com *lst)
{
    t_com *tmp;

    while (lst)
    {
        free(lst->com);
        // free(lst->vale);
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    
}

void  free_all(t_box *box)
{
    
    // if (box->cmd->com)
    //     printf("fwkergj");  
    free_lcom(box->l_com);
    free(box->cmd);

}