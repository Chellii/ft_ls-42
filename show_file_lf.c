/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_file_lf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 04:31:08 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 05:15:48 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	show_file_lf(t_tabav_lt *t1, t_pars_v *pv)
{
	t_majminvar majminvar;

	init_majminvar(&majminvar);
	permission(t1->buf.st_mode);
	show_stnlink((t1->buf).st_nlink, pv->hpmax_file->linkmax);
	show_pwname_file((t1->buf).st_uid, pv->hpmax_file->pwnmax);
	show_grname_file((t1->buf).st_gid, pv->hpmax_file->grnmax);
	if (S_ISCHR((t1->buf).st_mode) || S_ISBLK((t1->buf).st_mode))
	{
		majminvar.maj = major((t1->buf).st_rdev);
		majminvar.min = minor((t1->buf).st_rdev);
	}
	show_stsize((t1->buf).st_size, majminvar,
			(t1->buf).st_mode, pv->hpmax_file);
	show_ctime((t1->buf).st_mtime);
	ft_putstr(t1->nameav);
	ft_putchar('\n');
}
