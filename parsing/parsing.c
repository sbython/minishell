

#include "../minishell.h"

void free_2ptr(char **p)
{
    int i;

    i = 0;
    while(p[i])
        free(p[i++]);
    free(p);
}

void  parsing(t_box *box)
{

    char **ptr;
    
    simple_check(box->cmd);
    ptr = ft_split(box->cmd , ' ');
    fill_list(ptr, box);
    free_2ptr(ptr);
    collect_string(box);
    replace_var(box);
    split_pip(box);
    

}
