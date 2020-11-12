/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 03:59:34 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/24 00:34:53 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	condition_fill_hpmax(t_pars_v *pv, struct stat *buf)
{
	if ((pv->flags & LS_A) == 0)
	{
		(ft_strncmp(pv->dh->name, ".", 1) == 0) ? fill_hpmax(pv->hpmax, buf, 0)
			: fill_hpmax(pv->hpmax, buf, 1);
	}
	else
		fill_hpmax(pv->hpmax, buf, 1);
}

void	fill_dh(t_pars_v *pv, t_rdir rdir, char *nameav)
{
	pv->dh->name = ft_strdup((rdir.d)->d_name);
	pv->dh->dtype = (rdir.d)->d_type;
	pv->dh->fpath = ft_strdup(nameav);
}

int		condition(t_pars_v *pv)
{
	if (((pv->flags & LS_T) || (pv->flags & LS_L) || (pv->flags & LS_BR)))
		return (1);
	else
		return (0);
}

void	read_dir_2(t_list_ls **lt, t_pars_v *pv, t_rdir rdir)
{
	condition_fill_hpmax(pv, &(rdir.buf));
	if ((pv->pars_var == 1 || pv->pars_var == 3))
		(*lt) = ((pv->flags & LS_T) == 0) ? (ltinsr(lt, pv))
			: (ltinsr_tflag(lt, pv));
	else if ((pv->pars_var == 0 || pv->pars_var == 2))
		*lt = ltinsr(lt, pv);
}

void	read_dir(t_list_ls **lt, t_pars_v *pv, char *nameav)
{
	t_rdir	rdir;
	char	*path;

	errno = 0;
	if (!(rdir.rep = opendir(nameav)))
		(*lt) = error_directory(nameav);
	else
	{
		while ((rdir.d = readdir(rdir.rep)) != NULL)
		{
			fill_dh(pv, rdir, nameav);
			path = remplir_name(pv->dh->fpath, pv->dh->name);
			if (!((condition(pv)) && (rdir.b = lstat(path, &(rdir.buf))) == -1))
			{
				read_dir_2(lt, pv, rdir);
				free(path);
			}
			else
				free_pv_path(pv, path);
		}
		if (closedir(rdir.rep) == -1)
			exit(1);
	}
}
