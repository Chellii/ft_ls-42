/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:50:03 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/22 01:16:23 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		cmp_mtime(struct stat buf1, struct stat buf2)
{
	if (buf1.st_mtime > buf2.st_mtime)
		return (1);
	else if (buf1.st_mtime < buf2.st_mtime)
		return (-1);
	else
		return (0);
}

void	pars_ac_2(t_pars_v *pv, char **av)
{
	pars_flags(av, pv);
	if (pv->flags == -1)
		pv->pars_var = -1;
	else if (pv->flags == 0)
		pv->pars_var = 2;
	else
		pv->pars_var = 1;
}

void	is_spec_case(int ac, char **av, t_pars_v *pv)
{
	int i;

	i = 1;
	while ((i < ac) && (ft_strcmp(av[i], "--") != 0))
		i++;
	if ((i < ac) && (ft_strcmp(av[i], "--") == 0)
			&& ((i == 1) || (ft_strncmp(av[i - 1], "-", 1) == 0)))
		pv->spec_case = i;
}

void	parsing_2(t_pars_v *pv, int ac, char **av)
{
	if (pv->flags == -1)
		pv->pars_var = -1;
	else if (pv->flags == 0)
		pv->pars_var = 2;
	else
	{
		pv->dir_case = is_dir(ac, av, pv->spec_case);
		if (pv->dir_case == 0)
			(pv->pars_var = 2);
		else
		{
			(pv->pars_var = 3);
			if ((pv->nb_dir = case_dir_nb(ac, av, pv)) == ac)
			{
				av[pv->nb_dir + 1] = NULL;
				av[pv->nb_dir] = ft_strdup(".");
			}
		}
		pv->nb_dir = case_dir_nb(ac, av, pv);
	}
}

void	parsing(t_pars_v *pv, int ac, char **av)
{
	if (ac == 1)
		pv->pars_var = 0;
	if (ac > 1)
	{
		if ((ac == 2) && (ft_strncmp(av[1], "-", 1) == 0))
			pars_ac_2(pv, av);
		else if ((ac == 2) && (ft_strncmp(av[1], "-", 1) != 0))
			pv->pars_var = 2;
		else if (ac > 2)
		{
			is_spec_case(ac, av, pv);
			if ((ft_strncmp(av[1], "-", 1) == 0) && (pv->spec_case != 1))
			{
				pars_flags(av, pv);
				parsing_2(pv, ac, av);
			}
			else
			{
				pv->pars_var = 2;
				pv->nb_dir = case_dir_nb(ac, av, pv);
			}
		}
	}
}
