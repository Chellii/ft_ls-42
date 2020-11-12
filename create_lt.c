/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:21:18 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/24 01:21:47 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_inexist_df(char *str, int t_errno)
{
	char *path;

	path = concat_str("ls: ", str);
	ft_putstr(path);
	ft_putstr(": ");
	ft_putendl(strerror(t_errno));
	free(path);
}

void	show_name_av(char *str)
{
	ft_putstr(str);
	ft_putstr(":\n");
}

void	show_files_list(t_tabav_lt *t1, t_pars_v *pv)
{
	if ((pv->flags & LS_L) != 0)
		show_file_lf(t1, pv);
	else
		ft_putendl(t1->nameav);
	if ((t1->next != NULL) && (S_ISDIR((t1->next->buf).st_mode) == 1))
		ft_putchar('\n');
}

void	create_lt_2(t_pars_v *pv, t_list_ls *lt, t_tabav_lt *t1)
{
	read_dir(&lt, pv, t1->nameav);
	((pv->flags & LS_R) != 0) ? (lt = reverse_list_r(&lt)) : NULL;
	((pv->flags & LS_L) != 0) ? (affich_list_l(lt)) : (affich_list(lt));
	if (t1->next != NULL)
		ft_putchar('\n');
	((pv->flags & LS_BR) != 0) ? (read_dir_br(lt, pv)) : NULL;
	freelist(&lt);
}

void	create_lt(t_pars_v *pv)
{
	t_tabav_lt	*t1;
	t_list_ls	*lt;
	int			n;

	lt = NULL;
	n = lst_len(pv->t);
	t1 = pv->t;
	while (t1 != NULL)
	{
		if (t1->exist == 0)
			show_inexist_df(t1->nameav, t1->t_errno);
		else
		{
			if (S_ISDIR((t1->buf).st_mode) != 1)
				show_files_list(t1, pv);
			else
			{
				if (n != 1)
					show_name_av(t1->nameav);
				create_lt_2(pv, lt, t1);
			}
		}
		t1 = t1->next;
	}
}
