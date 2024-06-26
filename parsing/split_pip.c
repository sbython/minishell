
#include "../minishell.h"

char *new_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
        if (s[i] == '\'' || s[i] == '"')
        {
            i++;
            while (s[i] && s[i] != '\'' && s[i] != '"')
                i++;
        }
        else if ((char)c == s[i])
			return ((char *)(&s[i]));
		else
            i++;
	}
	if ((char)c == s[i])
		return ((char *)(&s[i]));
	return (NULL);
}
void catit(t_com *com , char *pip1)
{
    t_com * next;
    t_com *node;
    t_com *pip;
    char *new;

    next = com->next;
    // prev = com->prev;
    new = new_strchr(com->com, *pip1);
    *new = 0;
    new += 1;
    new = ft_strdup(new);
    node = new_node(new);
    node->next =next;
    pip = new_node(ft_strdup(pip1));
    com->next = pip;
    pip->prev = com;
    pip->next = node;
    node->prev = pip;

}
void split_pip(t_box *box)
{
    t_com * com;

    com = box->l_com;
    while (com)
    {
        // pri ntf(com->com);

        if(new_strchr(com->com, '|'))
        {
            catit(com , "|");
            com = com->next;
        }
        else if(new_strchr(com->com, '<'))
        {
            catit(com , "<");
            com = com->next;
        }
        else if(new_strchr(com->com, '>'))
        {
                catit(com , ">");
            com = com->next;
        }
        com = com->next;
    }
}
