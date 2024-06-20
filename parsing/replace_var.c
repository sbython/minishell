
#include "../minishell.h"


int len_to(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
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
char * get_val(char *str , env * en)
{
    while (en)
    {
        if(!ft_strncmp(str, en->name, ft_strlen(str)))
            return (ft_strdup(en->vale));
        en = en->next;
    }
    // free(str);
    return ft_strdup("");
}
// ptr[0] it is a return string 
// ptr[1] it name of variable 
// ptr[2] it is left string after take a ptr[1] or ptr [0]
void replace(char *str , env * en)
{
    char *ptr[3];
    
    ptr[0] = get_to(str, '$');
    ptr[2] = str;
    while ((ptr[2] =  ft_strchr(ptr[2], '$')))
    {
        ptr[1] = get_to(ptr[2], ' ');
        ptr[1] = get_val(ptr[1] + 1, en);
        printf("%s --\n",ptr[1]);
        ptr[2] =  ft_strchr(ptr[2] + 1, '$');
        if (!ptr[2])
            return;
    }
    
}

void replace_var(t_box *box)
{
    t_com *com;

    com = box->l_com;
    while (com)
    {
        if (ft_strchr(com->com, '$'))
        {
            replace(com->com, box->env);
        }
        com = com->next;
    }
}