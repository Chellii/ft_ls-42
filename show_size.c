/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 06:36:31 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 07:05:29 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_size_majmin(t_helpmax *hpmax, t_majminvar majminvar)
{
	int size;

	size = size_of_majmin(size_nbr_int(majminvar.maj),
			size_nbr_int(majminvar.min));
	while ((hpmax->sizemax - size) != 0)
	{
		ft_putchar(' ');
		size++;
	}
	ft_putnbr(majminvar.maj);
	ft_putstr(", ");
	size = size_nbr_int(majminvar.min);
	while ((hpmax->minmax - size) != 0)
	{
		ft_putchar(' ');
		size++;
	}
	ft_putnbr(majminvar.min);
}

void	show_size_majsize(t_helpmax *hpmax, t_majminvar majminvar)
{
	int size;

	size = size_nbr_int(majminvar.maj);
	while ((hpmax->majmax - size) != 0)
	{
		ft_putchar(' ');
		size++;
	}
	ft_putnbr(majminvar.maj);
	ft_putstr(", ");
	size = size_nbr_int(majminvar.min);
	while ((hpmax->minmax - size) != 0)
	{
		ft_putchar(' ');
		size++;
	}
	ft_putnbr(majminvar.min);
}

void	show_stsize_1(off_t stsize, t_majminvar majminvar,
		mode_t stmode, t_helpmax *hpmax)
{
	int size;

	if (S_ISCHR(stmode) || S_ISBLK(stmode))
		show_size_majmin(hpmax, majminvar);
	else
	{
		size = size_of_stsize(stsize);
		while ((hpmax->sizemax - size) != 0)
		{
			ft_putchar(' ');
			size++;
		}
		ft_putnbr(stsize);
	}
}

void	show_stsize_2(off_t stsize, t_majminvar majminvar,
		mode_t stmode, t_helpmax *hpmax)
{
	int size;

	if (S_ISCHR(stmode) || S_ISBLK(stmode))
		show_size_majsize(hpmax, majminvar);
	else
	{
		size = size_of_stsize(stsize);
		while ((hpmax->majmin - size) != 0)
		{
			ft_putchar(' ');
			size++;
		}
		ft_putnbr(stsize);
	}
}

void	show_stsize(off_t stsize, t_majminvar majminvar,
		mode_t stmode, t_helpmax *hpmax)
{
	int size;

	if (hpmax->majmin == 0)
	{
		size = size_of_stsize(stsize);
		while ((hpmax->sizemax - size) != 0)
		{
			ft_putchar(' ');
			size++;
		}
		ft_putnbr(stsize);
	}
	else
	{
		if (hpmax->sizemax > hpmax->majmin)
			show_stsize_1(stsize, majminvar, stmode, hpmax);
		else
			show_stsize_2(stsize, majminvar, stmode, hpmax);
	}
}
