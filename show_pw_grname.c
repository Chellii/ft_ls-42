/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_pw_grname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 06:51:16 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:57:17 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_pwname(t_list_ls *lt, int pwnmax)
{
	t_passwd	*pwd;
	int			size_name;
	int			size_max;

	size_max = pwnmax;
	if ((pwd = getpwuid((lt)->stuid)) != NULL)
	{
		ft_putchar(' ');
		ft_putstr(pwd->pw_name);
		size_name = (int)(ft_strlen(pwd->pw_name));
		while ((size_max - size_name) != 0)
		{
			ft_putchar(' ');
			size_name++;
		}
		ft_putstr("  ");
	}
}

void	show_pwname_file(uid_t stuid, int pwnmax)
{
	t_passwd	*pwd;
	int			size_name;
	int			size_max;

	size_max = pwnmax;
	if ((pwd = getpwuid(stuid)) != NULL)
	{
		ft_putchar(' ');
		ft_putstr(pwd->pw_name);
		size_name = (int)(ft_strlen(pwd->pw_name));
		while ((size_max - size_name) != 0)
		{
			ft_putchar(' ');
			size_name++;
		}
		ft_putstr("  ");
	}
}

void	show_grname(t_list_ls *lt, int grnmax)
{
	t_group *grp;
	int		size_max;
	int		size_name;

	size_max = grnmax;
	if ((grp = getgrgid((lt)->stgid)) != NULL)
	{
		ft_putstr(grp->gr_name);
		size_name = (int)(ft_strlen(grp->gr_name));
		while ((size_max - size_name) != 0)
		{
			ft_putchar(' ');
			size_name++;
		}
		ft_putstr("  ");
	}
}

void	show_grname_file(gid_t stgid, int grnmax)
{
	t_group	*grp;
	int		size_max;
	int		size_name;

	size_max = grnmax;
	if ((grp = getgrgid(stgid)) != NULL)
	{
		ft_putstr(grp->gr_name);
		size_name = (int)(ft_strlen(grp->gr_name));
		while ((size_max - size_name) != 0)
		{
			ft_putchar(' ');
			size_name++;
		}
		ft_putstr("  ");
	}
}
