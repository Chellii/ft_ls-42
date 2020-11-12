/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ltav_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 02:23:15 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 02:45:46 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_tabav_lt	*insert_files_r(t_tabav_lt **t, t_tabav_lt *lt)
{
	t_tabav_lt *lt2;

	lt2 = (*t);
	while ((lt2->next) && (lt2->exist == 0))
		lt2 = lt2->next;
	if ((lt2->exist == 0) && ((lt2->next) == NULL))
		insert_end(lt2, lt);
	else
	{
		while ((lt2->next) && ((S_ISDIR((&(lt2->buf))->st_mode)) != 1)
				&& (ft_strcmp(lt2->nameav, lt->nameav) > 0))
			lt2 = lt2->next;
		if ((ft_strcmp(lt2->nameav, lt->nameav) < 0)
				|| ((S_ISDIR((&(lt2->buf))->st_mode)) == 1))
			(*t) = insert_mid(lt2, lt);
		else
			insert_end(lt2, lt);
	}
	return (*t);
}

t_tabav_lt	*insert_dir_r(t_tabav_lt **t, t_tabav_lt *lt)
{
	t_tabav_lt *lt2;

	lt2 = (*t);
	while ((lt2->next) && (lt2->exist == 0))
		lt2 = lt2->next;
	if ((lt2->exist == 0) && ((lt2->next) == NULL))
		insert_end(lt2, lt);
	else
	{
		while ((lt2->next) && (!(isdir(lt2->buf))))
			lt2 = lt2->next;
		if (isdir(lt2->buf))
		{
			while ((lt2->next) && (ft_strcmp(lt2->nameav, lt->nameav) > 0))
				lt2 = lt2->next;
			if ((ft_strcmp(lt2->nameav, lt->nameav) < 0))
				(*t) = insert_mid(lt2, lt);
			else
				insert_end(lt2, lt);
		}
		else
			insert_end(lt2, lt);
	}
	return (*t);
}

t_tabav_lt	*fill_ltav_r(t_tabav_lt **t, char *str, t_pars_v *pv)
{
	t_tabav_lt *lt;

	lt = allocate_case_list(str);
	if ((*t) == NULL)
	{
		((lt->exist == 1) && (!(isdir(lt->buf))))
			? fill_hpmax(pv->hpmax_file, &(lt->buf), 0) : NULL;
		(*t) = lt;
		return (*t);
	}
	else
	{
		((lt->exist == 1) && (!(isdir(lt->buf))))
			? fill_hpmax(pv->hpmax_file, &(lt->buf), 0) : NULL;
		if (lt->exist == 0)
			(*t) = insert_inexist_df(t, lt);
		else if (!(isdir(lt->buf)))
			(*t) = insert_files_r(t, lt);
		else if ((isdir(lt->buf)))
			(*t) = insert_dir_r(t, lt);
		return (*t);
	}
}
