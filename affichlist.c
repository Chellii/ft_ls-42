/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:37:39 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/24 00:40:10 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <stdio.h>

void	permission(mode_t stmode)
{
	(S_ISBLK(stmode)) ? ft_putchar('b') : NULL;
	(S_ISCHR(stmode)) ? ft_putchar('c') : NULL;
	(S_ISDIR(stmode)) ? ft_putchar('d') : NULL;
	(S_ISLNK(stmode)) ? ft_putchar('l') : NULL;
	(S_ISSOCK(stmode)) ? ft_putchar('s') : NULL;
	(S_ISFIFO(stmode)) ? ft_putchar('p') : NULL;
	(S_ISREG(stmode)) ? ft_putchar('-') : NULL;
	(stmode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(stmode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (stmode & S_ISUID)
		(stmode & S_IXUSR) ? ft_putchar('s') : ft_putchar('S');
	else
		(stmode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(stmode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(stmode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (stmode & S_ISGID)
		(stmode & S_IXGRP) ? ft_putchar('s') : ft_putchar('S');
	else
		(stmode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(stmode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(stmode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (stmode & S_ISVTX)
		(stmode & S_IXOTH) ? ft_putchar('t') : ft_putchar('T');
	else
		(stmode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}

void	show_stnlink(nlink_t stnlink, int linkmax)
{
	int	link;

	ft_putstr("  ");
	link = size_of_stnlink(stnlink);
	while ((linkmax - link) != 0)
	{
		ft_putchar(' ');
		link++;
	}
	ft_putnbr(stnlink);
}

void	show_total(blkcnt_t total)
{
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void	affich_list_l(t_list_ls *lt)
{
	t_list_ls *lt2;

	if (lt)
	{
		lt2 = lt;
		if (lt != NULL)
			show_total(lt2->hpmax->total);
		while (lt2 != NULL)
		{
			permission(lt2->stmode);
			show_stnlink(lt2->stnlink, lt2->hpmax->linkmax);
			show_pwname(lt2, lt2->hpmax->pwnmax);
			show_grname(lt2, lt2->hpmax->grnmax);
			show_stsize(lt2->stsize, lt2->majminvar, lt2->stmode, lt2->hpmax);
			show_ctime(lt2->stmtime);
			ft_putstr(lt2->name);
			if (S_ISLNK(lt2->stmode))
			{
				ft_putstr(" -> ");
				ft_putstr(lt2->linkname);
			}
			ft_putchar('\n');
			lt2 = lt2->next;
		}
	}
}

void	affich_list(t_list_ls *lt)
{
	t_list_ls *lt2;

	if ((lt))
	{
		lt2 = lt;
		while (lt2 != NULL)
		{
			ft_putstr(lt2->name);
			ft_putstr("\n");
			lt2 = lt2->next;
		}
	}
}
