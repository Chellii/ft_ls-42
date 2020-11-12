/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 06:13:32 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:20:24 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		insert_end(t_tabav_lt *lt2, t_tabav_lt *lt)
{
	lt->prev = lt2;
	lt->next = lt2->next;
	if (lt2->next != NULL)
		lt2->next->prev = lt;
	lt2->next = lt;
}

t_tabav_lt	*insert_mid(t_tabav_lt *lt2, t_tabav_lt *lt)
{
	lt->next = lt2;
	lt->prev = lt2->prev;
	if (lt2->prev != NULL)
		lt2->prev->next = lt;
	lt2->prev = lt;
	while (lt2->prev != NULL)
		lt2 = lt2->prev;
	return (lt2);
}

void		insert_end_list(t_list_ls *lt2, t_list_ls *lt)
{
	lt->prev = lt2;
	lt->next = lt2->next;
	if (lt2->next != NULL)
		lt2->next->prev = lt;
	lt2->next = lt;
}

t_list_ls	*insert_mid_list(t_list_ls *lt2, t_list_ls *lt)
{
	lt->next = lt2;
	lt->prev = lt2->prev;
	if (lt2->prev != NULL)
		lt2->prev->next = lt;
	lt2->prev = lt;
	while (lt2->prev != NULL)
		lt2 = lt2->prev;
	return (lt2);
}
