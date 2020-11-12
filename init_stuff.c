/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:51:52 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:25:26 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	init_f(t_pars_v *pv)
{
	pv->pars_var = 0;
	pv->flags = 0;
	pv->spec_case = 0;
	pv->dir_case = 0;
	pv->nb_dir = 0;
	if (!(pv->hpmax = (t_helpmax*)malloc(sizeof(t_helpmax))))
		exit(1);
	if (!(pv->hpmax_file = (t_helpmax*)malloc(sizeof(t_helpmax))))
		exit(1);
	init_hpmax(pv->hpmax);
	init_hpmax(pv->hpmax_file);
	if (!(pv->dh = (t_dirent_h*)malloc(sizeof(t_dirent_h))))
		exit(1);
}

void	init_hpmax(t_helpmax *hpmax)
{
	hpmax->total = 0;
	hpmax->linkmax = 0;
	hpmax->sizemax = 0;
	hpmax->pwnmax = 0;
	hpmax->grnmax = 0;
	hpmax->majmax = 0;
	hpmax->minmax = 0;
	hpmax->majmin = 0;
}

void	init_majminvar(t_majminvar *majminvar)
{
	majminvar->maj = 0;
	majminvar->min = 0;
}
