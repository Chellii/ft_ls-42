/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 04:58:27 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 04:59:08 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#include "ls.h"

int		lst_len(t_tabav_lt *t)
{
	t_tabav_lt	*t2;
	int			i;

	t2 = t;
	i = 0;
	while (t2 != NULL)
	{
		i++;
		t2 = t2->next;
	}
	return (i);
}

int		main(int ac, char **av)
{
	t_pars_v	*pv;
	int			i;

	i = 0;
	if (!(pv = (t_pars_v*)malloc(sizeof(t_pars_v))))
		return (1);
	init_f(pv);
	parsing(pv, ac, av);
	if (pv->pars_var == -1)
	{
		free(pv->hpmax);
		free(pv->hpmax_file);
		free(pv->dh);
		free(pv);
		return (1);
	}
	pars_directory(ac, av, pv);
	create_lt(pv);
	free_pv(pv);
	return (0);
}
