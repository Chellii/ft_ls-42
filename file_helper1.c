/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 04:15:50 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 04:54:34 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		size_of_stsize(off_t stsize)
{
	int i;

	i = 0;
	if (stsize == 0)
		return (1);
	while (stsize != 0)
	{
		stsize = stsize / 10;
		i++;
	}
	return (i);
}

int		size_of_stnlink(nlink_t stlink)
{
	int i;

	i = 0;
	while (stlink != 0)
	{
		stlink = stlink / 10;
		i++;
	}
	return (i);
}

int		size_of_majmin(int majmax, int minmax)
{
	int i;

	i = 2 + majmax + minmax;
	return (i);
}

int		size_nbr_int(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
