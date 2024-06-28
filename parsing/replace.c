
#include "../minishell.h"

char * str_replace(char * s1, char *rep, char *with)
{
    size_t rep_len = ft_strlen(rep);
    size_t with_len = ft_strlen(with);
    char * result = malloc(ft_strlen(s1) +(with_len - rep_len) + 1);

    char *res_pos = result;
    char *pos;
    while ((pos = ft_strnstr(s1, rep , -1)))
    {
        size_t len = pos - s1;
        ft_memcpy(res_pos, s1 , len);
        res_pos += len;
        ft_memcpy(res_pos, with , with_len);
        res_pos +=  with_len;
        s1 = pos + rep_len;
    }
    ft_strlcpy(res_pos, s1 , -1);
    return (result);
}
