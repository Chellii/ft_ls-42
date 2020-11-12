/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 06:34:05 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/24 00:36:45 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	show_ctime_2(time_t stmtime, time_t timemax, int i, char *s)
{
	int n;

	n = ft_strlen(s);
	if (stmtime < timemax)
	{
		ft_putstr("  ");
		i = n - 5;
		while (i < (n - 1))
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	else
	{
		ft_putchar(' ');
		i = n - 14;
		while (i < (n - 9))
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

void	show_ctime(time_t stmtime)
{
	int		i;
	int		n;
	char	*s;
	time_t	timemax;

	timemax = time(&timemax) - 15768000;
	s = (ctime(&(stmtime)));
	n = ft_strlen(s);
	i = 4;
	ft_putchar(' ');
	while (i < (n - 15))
	{
		ft_putchar(s[i]);
		i++;
	}
	show_ctime_2(stmtime, timemax, i, s);
	ft_putchar(' ');
}
