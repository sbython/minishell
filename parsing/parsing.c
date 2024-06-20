

#include "../minishell.h"



void  parsing(t_box *box)
{
    char **ptr;
    t_com *ls;
    ptr = ft_split(box->cmd , ' ');
    fill_list(ptr, box);
    replace_var(box);
    ls = box->l_com;
    while (ls)
    {
        printf("%s\n", ls->com);
        ls = ls->next;
    }
    
}