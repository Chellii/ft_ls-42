/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:24:40 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/22 00:10:24 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		verif_flags(char f)
{
	int flag;

	if (f == 'a')
		flag = LS_A;
	else if (f == 'l')
		flag = LS_L;
	else if (f == 'r')
		flag = LS_R;
	else if (f == 't')
		flag = LS_T;
	else if (f == 'R')
		flag = LS_BR;
	else
		flag = -1;
	return (flag);
}

int		cal_flags(char *f)
{
	int flags;
	int flag;
	int n;
	int i;

	flags = 0;
	i = 1;
	n = ft_strlen(f);
	while (i < n)
	{
		if (((flag = verif_flags(f[i])) == -1))
		{
			ft_putendl(strerror(errno));
			gest_error(1, f[i]);
			return (-1);
		}
		else
			((flags & flag) == 0) ? (flags |= flag) : flags;
		i++;
	}
	return (flags);
}

void	pars_flags(char **av, t_pars_v *pv)
{
	int i;

	i = 1;
	if (pv->spec_case != 0)
	{
		while (i < pv->spec_case)
		{
			pv->flags |= cal_flags(av[i]);
			i++;
		}
	}
	else
	{
		while ((av[i]) && (ft_strncmp(av[i], "-", 1) == 0))
		{
			pv->flags |= cal_flags(av[i]);
			i++;
		}
	}
}
