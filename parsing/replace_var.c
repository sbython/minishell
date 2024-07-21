/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:08 by msbai             #+#    #+#             */
/*   Updated: 2024/07/21 13:35:29 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_to(char *str, char c)
{
	int	i;

	i = 1;
	(void)c;
	if (str[1] == '?' || ft_isdigit(str[1]))
		return (2);
	else if (str[1] == '"' || str[1] == '\'')
		return (1);
	else if (!(ft_isalpha(str[1]) || ft_isdigit(str[1])) && str[1] != '_')
		return (0);
	while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i])
			|| str[i] == '_'))
	{
		i++;
	}
	return (i);
}

char	*get_to(char *str, char c)
{
	char	*p;
	int		len;

	len = len_to(str, c);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, str, len);
	p[len] = '\0';
	return (p);
}

char	*get_val(char *str, t_env *en, t_box *box)
{
	
	if (!ft_strncmp(str, "?", 2))
		return (ft_itoa(box->exit_val));
	while (en)
	{
		if (!ft_strncmp(str, en->name, -1))
			return (ft_strdup(en->vale));
		en = en->next;
	}
	return (ft_strdup(""));
}

/*
	* ptr[0] it is a return string
	* ptr[1] it name of variable
	* ptr[2] it is left string after take a ptr[1] or ptr [0]
*/
char	*replace(t_com *str, t_box *box)
{
	char	*ptr[5];
	
	str->type = -1;
	ptr[4] = ft_strdup(str->com);
	ptr[3] = ft_strdup(str->com);
	ptr[2] = ptr[4];
	ptr[2] = ft_dchr(ptr[2], '$');
	while (ptr[2])
	{
		ptr[1] = get_to(ptr[2], ' ');
		ptr[0] = get_val(ptr[1] + 1, box->env, box);
		ptr[3] = str_replace(ptr[3], ptr[1], ptr[0]);
		free(ptr[1]);
		free(ptr[0]);
		ptr[2] = ft_dchr(ptr[2] + 1, '$');
	}
	free(ptr[4]);
	return (ptr[3]);
}

void	replace_var(t_box *box)
{
	t_com	*com;
	char	*str;

	com = box->l_com;
	while (com)
	{
		if ((ft_dchr(com->com, '$') && ((com->prev && com->prev->type != 4)
					|| !com->prev)))
		{
			str = replace(com, box);
			if (!*str && com->prev && ft_isdelimiter(com->prev->com))
				free(str);
			else if (ft_strchr(str, '"') || !*str)
			{
				free(com->com);
				com->com = str;
			}
			else
				sp(&com, str, com->next, &box->l_com);
		}
		else if (com->com[0] == '~' && (com->com[1] == 0 || com->com[1] == '/'))
			com->com = str_replace(com->com, "~", get_val("HOME", box->env,
						box));
		com = com->next;
	}
}
