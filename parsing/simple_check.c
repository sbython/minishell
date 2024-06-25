
#include "../minishell.h"

void exit_f(char *s)
{
    ft_putstr_fd("haver a error near: | , << , >> , > or <\n", 2);
    free(s);
    exit(1);
}

void simple_check(char *com)
{
    if (com[0] == '|' || com[ft_strlen(com) - 1] == '|')
         exit_f(com);
    else if (!(ft_strncmp(com , "<<", -1) 
    && ft_strncmp(com , ">", -1) 
    && ft_strncmp(com , "<", -1) 
    && ft_strncmp(com , ">>", -1)))
        {exit_f(com); }   
    
}