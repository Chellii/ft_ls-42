/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:31:29 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/22 01:13:01 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	freelist(t_list_ls **lt)
{
	t_list_ls *lt_tracker;

	lt_tracker = (*lt);
	while (lt_tracker != NULL)
	{
		if (lt_tracker != NULL)
			(*lt) = lt_tracker->next;
		free(lt_tracker->name);
		free(lt_tracker->path);
		free(lt_tracker->av);
		if (lt_tracker->linkname != NULL)
			free(lt_tracker->linkname);
		free(lt_tracker);
		lt_tracker = (*lt);
	}
	(*lt) = NULL;
}

void	free_pv_lt(t_tabav_lt **t)
{
	t_tabav_lt *pv_tracker;

	pv_tracker = (*t);
	while (pv_tracker != NULL)
	{
		if (pv_tracker != NULL)
			(*t) = pv_tracker->next;
		free(pv_tracker->nameav);
		free(pv_tracker);
		pv_tracker = (*t);
	}
	(*t) = NULL;
}

void	free_pv(t_pars_v *pv)
{
	free_pv_lt(&(pv->t));
	free(pv->hpmax);
	free(pv->hpmax_file);
	free(pv->dh);
	free(pv);
}

void	free_pv_path(t_pars_v *pv, char *path)
{
	free(pv->dh->name);
	free(pv->dh->fpath);
	free(path);
}
