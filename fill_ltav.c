/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ltav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:58:31 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 02:40:20 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int			isdir(struct stat buf)
{
	if ((S_ISDIR(buf.st_mode)) == 1)
		return (1);
	else
		return (0);
}

t_tabav_lt	*allocate_case_list(char *str)
{
	t_tabav_lt	*lt;
	int			b;

	if (!(lt = (t_tabav_lt*)malloc(sizeof(t_tabav_lt))))
		exit(1);
	lt->nameav = ft_strdup(str);
	lt->next = NULL;
	lt->prev = NULL;
	b = lstat(str, &(lt->buf));
	lt->exist = (b == -1) ? 0 : 1;
	lt->t_errno = (b == -1) ? errno : 0;
	return (lt);
}

t_tabav_lt	*insert_files(t_tabav_lt **t, t_tabav_lt *lt)
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
				&& (ft_strcmp(lt2->nameav, lt->nameav) < 0))
			lt2 = lt2->next;
		if ((ft_strcmp(lt2->nameav, lt->nameav) > 0)
				|| ((S_ISDIR((&(lt2->buf))->st_mode)) == 1))
			(*t) = insert_mid(lt2, lt);
		else
			insert_end(lt2, lt);
	}
	return (*t);
}

t_tabav_lt	*insert_dir(t_tabav_lt **t, t_tabav_lt *lt)
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
			while ((lt2->next) && (ft_strcmp(lt2->nameav, lt->nameav) < 0))
				lt2 = lt2->next;
			if ((ft_strcmp(lt2->nameav, lt->nameav) > 0))
				(*t) = insert_mid(lt2, lt);
			else
				insert_end(lt2, lt);
		}
		else
			insert_end(lt2, lt);
	}
	return (*t);
}

t_tabav_lt	*fill_ltav(t_tabav_lt **t, char *str, t_pars_v *pv)
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
			(*t) = insert_files(t, lt);
		else if ((isdir(lt->buf)))
			(*t) = insert_dir(t, lt);
		return (*t);
	}
}
