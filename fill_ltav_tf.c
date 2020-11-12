/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ltav_tf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:35:27 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/22 00:13:28 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_tabav_lt	*insert_inexist_df(t_tabav_lt **t, t_tabav_lt *lt)
{
	t_tabav_lt *lt2;

	lt2 = (*t);
	while ((lt2->next) && (lt2->exist == 0) &&
	(ft_strcmp(lt2->nameav, lt->nameav) < 0))
		lt2 = lt2->next;
	if ((ft_strcmp(lt2->nameav, lt->nameav) > 0) || (lt2->exist != 0))
		(*t) = insert_mid(lt2, lt);
	else
		insert_end(lt2, lt);
	return (*t);
}

t_tabav_lt	*insert_dir_tf(t_tabav_lt **t, t_tabav_lt *lt)
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
		if ((isdir(lt2->buf)))
		{
			while ((lt2->next) && (cmp_mtime(lt2->buf, lt->buf) == 1))
				lt2 = lt2->next;
			if (lt2->buf.st_mtime < lt->buf.st_mtime)
				(*t) = insert_mid(lt2, lt);
			else
				insert_end(lt2, lt);
		}
		else
			insert_end(lt2, lt);
	}
	return (*t);
}

t_tabav_lt	*insert_files_tf_2(t_tabav_lt **t, t_tabav_lt *lt2, t_tabav_lt *lt)
{
	while ((lt2->next) && (!(isdir(lt2->buf)))
			&& ((cmp_mtime(lt2->buf, lt->buf)) == 0)
			&& (ft_strcmp(lt2->nameav, lt->nameav) < 0))
		lt2 = lt2->next;
	if ((isdir(lt2->buf)) || (lt2->buf.st_mtime != lt->buf.st_mtime)
			|| (ft_strcmp(lt2->nameav, lt->nameav) > 0))
		(*t) = insert_mid(lt2, lt);
	else
		insert_end(lt2, lt);
	return (*t);
}

t_tabav_lt	*insert_files_tf(t_tabav_lt **t, t_tabav_lt *lt)
{
	t_tabav_lt *lt2;

	lt2 = (*t);
	while ((lt2->next) && (lt2->exist == 0))
		lt2 = lt2->next;
	if ((lt2->exist == 0) && ((lt2->next) == NULL))
		insert_end(lt2, lt);
	else
	{
		while ((lt2->next) && (!(isdir(lt2->buf)))
				&& ((cmp_mtime(lt2->buf, lt->buf)) == 1))
			lt2 = lt2->next;
		if (lt2->buf.st_mtime == lt->buf.st_mtime)
			insert_files_tf_2(t, lt2, lt);
		else if ((cmp_mtime(lt2->buf, lt->buf) < 0) || (isdir(lt2->buf)))
			(*t) = insert_mid(lt2, lt);
		else
			insert_end(lt2, lt);
	}
	return (*t);
}

t_tabav_lt	*fill_ltav_ft(t_tabav_lt **t, char *str, t_pars_v *pv)
{
	t_tabav_lt *lt;

	lt = allocate_case_list(str);
	if ((*t) == NULL)
	{
		((lt->exist == 1) && (!(isdir(lt->buf))))
			? fill_hpmax(pv->hpmax_file, &(lt->buf), 0) : NULL;
		(*t) = lt;
	}
	else
	{
		((lt->exist == 1) && (!(isdir(lt->buf))))
			? (fill_hpmax(pv->hpmax_file, &(lt->buf), 0)) : NULL;
		if (lt->exist == 0)
			(*t) = insert_inexist_df(t, lt);
		else if ((!isdir(lt->buf)))
			(*t) = insert_files_tf(t, lt);
		else
			(*t) = insert_dir_tf(t, lt);
	}
	return (*t);
}
