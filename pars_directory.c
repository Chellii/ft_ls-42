/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:06:11 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 02:50:42 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		is_dir(int n, char **av, int spec_case)
{
	int i;
	int k;

	i = 1;
	while ((i < spec_case) && (ft_strncmp(av[i], "-", 1) == 0) &&
	(ft_strlen(av[i]) != 1))
		i++;
	if (i == n)
		k = (spec_case == 0) ? 0 : 1;
	else
		(k = 1);
	return (k);
}

int		case_dir_nb(int ac, char **av, t_pars_v *pv)
{
	int i;

	i = 1;
	if (pv->spec_case == 0)
	{
		while ((i < ac) && (ft_strncmp(av[i], "-", 1) == 0)
				&& (ft_strlen(av[i]) != 1))
			i++;
	}
	else
	{
		while ((i < ac) && (ft_strncmp(av[i], "-", 1) == 0) &&
		(ft_strcmp(av[i], "--") != 0) && (ft_strlen(av[i]) != 1))
			i++;
		if (ft_strcmp(av[i], "--") == 0)
			i++;
	}
	return (i);
}

void	pars_vardir_2(t_pars_v *pv, char **av, int ac)
{
	int i;

	i = pv->nb_dir;
	pv->t = NULL;
	while (i < ac)
	{
		pv->t = fill_ltav(&(pv->t), av[i], pv);
		i++;
	}
}

void	pars_vardir_3(t_pars_v *pv, char **av, int ac)
{
	int i;

	pv->t = NULL;
	i = pv->nb_dir;
	while (i < ac)
	{
		if ((pv->flags & LS_T) == 0)
		{
			((pv->flags & LS_R) != 0) ? (pv->t = fill_ltav_r(&(pv->t),
					av[i], pv)) : (pv->t = fill_ltav(&(pv->t), av[i], pv));
		}
		else
		{
			((pv->flags & LS_R) != 0) ? (pv->t = fill_ltav_rft(&(pv->t), av[i],
					pv)) : (pv->t = fill_ltav_ft(&(pv->t), av[i], pv));
		}
		i++;
	}
}

void	pars_directory(int ac, char **av, t_pars_v *pv)
{
	if ((pv->pars_var == 0) || (pv->pars_var == 1))
	{
		pv->t = NULL;
		pv->t = fill_ltav(&(pv->t), ".", pv);
	}
	else if (pv->pars_var == 2)
	{
		if (ac > 2)
			pars_vardir_2(pv, av, ac);
		else
		{
			pv->t = NULL;
			pv->t = fill_ltav(&(pv->t), av[1], pv);
			pv->nb_dir = 1;
		}
	}
	else if (pv->pars_var == 3)
		pars_vardir_3(pv, av, ac);
}
