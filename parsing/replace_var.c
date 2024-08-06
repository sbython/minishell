/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:12:08 by msbai             #+#    #+#             */
/*   Updated: 2024/08/06 17:16:29 by msbai            ###   ########.fr       */
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
	char	*li;
	int		i;
	
	str->type = -1;
	ptr[1] = str->com;
	ptr[2] = ft_strdup("");
	i = 0;
	li = ft_strdup(" ");
	while (ptr[1] && ptr[1][i])
	{
		if (ptr[1][i] == '\'')
		{
			ptr[3] = ft_substr(&ptr[1][i + 1], 0, slen(&ptr[1][i]) - 2);
			i += slen(&ptr[1][i]);
			join(&ptr[2], ptr[3],1);
		}
		else if (ptr[1][i] == '\"')
		{
			i++;
			while (ptr[1][i] != '\"')
			{
				if (ptr[1][i] == '$')
				{
					ptr[3] = get_to(&ptr[1][i], ' ');
					ptr[4] = get_val(ptr[3] + 1, box->env, box);
					i += ft_strlen(ptr[3]);
					free(ptr[3]);
					join(&ptr[2], ptr[4],1);
				}
				else
				{
					*li = ptr[1][i];
					join(&ptr[2], li,0);
					i++;
				}
				
			}
			i++;
		}
		else if (ptr[1][i] == '$')
		{
			ptr[3] = get_to(&ptr[1][i], ' ');
			ptr[4] = get_val(ptr[3] + 1, box->env, box);
			// remove_spes(ptr[4]);
			if(!ptr[3][0])
			{
				*li = ptr[1][i];
				join(&ptr[2], li,0);
				i++;
			}
			else
			{
				i += ft_strlen(ptr[3]) ;
				join(&ptr[2], ptr[4],1);
			}
			free(ptr[3]);
		}
		else
		{
			*li = ptr[1][i];
			join(&ptr[2], li,0);
			i++;
		}
	}
	free(li);
	return (ptr[2]);
	// ptr[4] = ft_strdup(str->com);
	// ptr[3] = ft_strdup(str->com);
	// ptr[2] = ptr[4];
	// ptr[2] = ft_dchr(ptr[2], '$');
	// while (ptr[2])
	// {
	// 	ptr[1] = get_to(ptr[2], ' ');
	// 	ptr[0] = get_val(ptr[1] + 1, box->env, box);
	// 	ptr[3] = str_replace(ptr[3], ptr[1], ptr[0]);
	// 	free(ptr[1]);
	// 	free(ptr[0]);
	// 	ptr[2] = ft_dchr(ptr[2] + 1, '$');
	// }
	
	// free(ptr[4]);
	// return (ptr[3]);
}

void	replace_var(t_box *box)
{
	t_com	*com;
	char	*str;

	com = box->l_com;
	while (com)
	{
		if ((ft_dchr(com->com, '$') && ((com->prev && !ft_isdelimiter(com->prev->com))
					|| !com->prev)))
		{
			str = replace(com, box);
			if (!*str )
			{
				free(com->com);
				com->com = str;
			}
			else
				sp(&com, str, com->next, &box->l_com);
		}
		else if (com->prev && 	ft_isdelimiter(com->prev->com))
			com->type = -1;
			
		com = com->next;
	}
}
