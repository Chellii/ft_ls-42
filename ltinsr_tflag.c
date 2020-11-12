/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltinsr_tflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 05:59:51 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:24:16 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_list_ls	*ltinsr_tflag_2(t_list_ls **lt, t_list_ls *lt2)
{
	t_list_ls *lt3;

	lt3 = *lt;
	while ((lt3->next != NULL) && (lt3->stmtime > lt2->stmtime))
		lt3 = lt3->next;
	if (lt3->stmtime == lt2->stmtime)
	{
		while ((lt3->next != NULL) && (lt3->stmtime == lt2->stmtime)
		&& (ft_strcmp(lt3->name, lt2->name) < 0))
			lt3 = lt3->next;
		if ((lt3->stmtime != lt2->stmtime) || (ft_strcmp(lt3->name,
		lt2->name) > 0))
			(*lt) = insert_mid_list(lt3, lt2);
		else
			insert_end_list(lt3, lt2);
	}
	else if (lt3->stmtime < lt2->stmtime)
		(*lt) = insert_mid_list(lt3, lt2);
	else
		insert_end_list(lt3, lt2);
	return (*lt);
}

t_list_ls	*ltinsr_tflag(t_list_ls **lt, t_pars_v *pv)
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
		(*lt) = lt2;
	else
		(*lt) = ltinsr_tflag_2(lt, lt2);
	return (*lt);
}
