/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_br.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 03:25:17 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 05:14:19 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_read_path(char *path)
{
	ft_putstr("\n");
	ft_putstr(path);
	ft_putstr(":\n");
}

void	read_show_dir(t_pars_v *pv, t_list_ls **lt, char *path)
{
	init_hpmax(pv->hpmax);
	show_read_path(path);
	read_dir(lt, pv, path);
}

void	read_dir_br(t_list_ls *lt, t_pars_v *pv)
{
	t_list_ls	*lt1;
	int			b;
	struct stat	buf;

	lt1 = lt;
	if (lt1)
	{
		while (lt1)
		{
			b = lstat(lt1->path, &buf);
			if ((S_ISDIR(lt1->stmode)) != 0)
			{
				lt = NULL;
				if ((ft_strcmp(lt1->name, ".") != 0)
						&& (ft_strcmp(lt1->name, "..") != 0))
					read_show_dir(pv, &lt, lt1->path);
				((pv->flags & LS_R) != 0) ? (lt = reverse_list_r(&lt)) : NULL;
				((pv->flags & LS_L) != 0) ? (affich_list_l(lt))
					: (affich_list(lt));
				read_dir_br(lt, pv);
				freelist(&lt);
			}
			lt1 = lt1->next;
		}
	}
}
