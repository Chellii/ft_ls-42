/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstinsr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:45:23 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:22:09 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		majminvar_value(t_majminvar *mvar, struct stat buf)
{
	mvar->maj = major(buf.st_rdev);
	mvar->min = minor(buf.st_rdev);
}

t_list_ls	*reverse_list_r(t_list_ls **lt)
{
	t_list_ls *lt1;
	t_list_ls *lt2;

	if ((*lt))
	{
		lt1 = (*lt);
		while (lt1->next != NULL)
			lt1 = lt1->next;
		lt2 = lt1;
		(*lt) = lt2;
		while (lt1 != NULL)
		{
			lt1 = lt1->prev;
			lt2->next = lt1;
			if (lt2->next != NULL)
				lt2 = lt2->next;
		}
	}
	return (*lt);
}

t_list_ls	*ltinsr_2(t_list_ls **lt, t_list_ls *lt2)
{
	t_list_ls *lt3;

	lt3 = *lt;
	while ((lt3->next != NULL) && (ft_strcmp(lt2->name, lt3->name) > 0))
		lt3 = lt3->next;
	if (ft_strcmp(lt2->name, lt3->name) < 0)
		(*lt) = insert_mid_list(lt3, lt2);
	else
		insert_end_list(lt3, lt2);
	return (*lt);
}

t_list_ls	*ltinsr(t_list_ls **lt, t_pars_v *pv)
{
	t_list_ls *lt2;

	lt2 = fill_lt(pv->dh, pv->hpmax);
	if ((pv->flags & LS_A) == 0)
	{
		if (ft_strncmp(lt2->name, ".", 1) == 0)
		{
			free(lt2->name);
			free(lt2->path);
			free(lt2->av);
			if (lt2->linkname != NULL)
				free(lt2->linkname);
			free(lt2);
			return ((*lt));
		}
	}
	if ((*lt) == NULL)
	{
		(*lt) = lt2;
		return (*lt);
	}
	else
		(*lt) = ltinsr_2(lt, lt2);
	return (*lt);
}
