/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:25:26 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/24 00:40:27 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		*concat_str(char *str1, char *str2)
{
	char	*path;
	int		i;
	int		j;

	if (!(path = (char*)malloc(sizeof(char)
					* (ft_strlen(str1) + ft_strlen(str2) + 1))))
		exit(1);
	i = 0;
	j = 0;
	while (str1[i])
	{
		path[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i])
	{
		path[j] = str2[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

void		gest_error(int x, char f)
{
	if (x == 1)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putendl(&f);
		ft_putendl("usage: ls [Ralrt] [file ...]");
	}
}

char		*concat_str_index(char *str1, char *str2, int i)
{
	int		n;
	char	*path;
	int		j;
	int		k;

	n = ft_strlen(str2);
	n = n - i;
	j = 0;
	k = 0;
	path = (char*)malloc(sizeof(char) * ((ft_strlen(str1)) + n + 1));
	while (str1[j])
	{
		path[k] = str1[j];
		j++;
		k++;
	}
	while (str2[i])
	{
		path[k] = str2[i];
		k++;
		i++;
	}
	path[k] = '\0';
	return (path);
}

t_list_ls	*error_directory(char *nameav)
{
	char	*path;
	int		i;

	i = ft_strlen(nameav);
	i--;
	while ((i >= 0) && (nameav[i] != '/'))
		i--;
	i++;
	path = concat_str_index("ls: ", nameav, i);
	perror(path);
	free(path);
	return (NULL);
}
