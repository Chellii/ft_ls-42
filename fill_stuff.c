/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 04:42:57 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:18:59 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		fill_majmin(t_helpmax *hpmax, struct stat *buf)
{
	if (size_nbr_int((major(buf->st_rdev))) > hpmax->majmax)
		hpmax->majmax = size_nbr_int(major(buf->st_rdev));
	if (size_nbr_int((minor(buf->st_rdev))) > hpmax->minmax)
		hpmax->minmax = size_nbr_int(minor(buf->st_rdev));
	if (size_of_majmin(hpmax->majmax, hpmax->minmax) > hpmax->majmin)
		hpmax->majmin = size_of_majmin(hpmax->majmax, hpmax->minmax);
}

char		*get_link(struct stat *buf, char *path)
{
	char	*linkname;
	ssize_t	r;

	(buf->st_size != 0) ? (linkname = ft_strnew(buf->st_size)) :
	(linkname = ft_strnew(256));
	(buf->st_size != 0) ? (r = readlink(path, linkname, buf->st_size + 1))
		: (r = readlink(path, linkname, 257));
	return (linkname);
}

t_list_ls	*fill_lt(t_dirent_h *dh, t_helpmax *hpmax)
{
	int				b;
	struct stat		buf;
	t_list_ls		*lt;

	if (!(lt = (t_list_ls*)malloc(sizeof(t_list_ls))))
		exit(1);
	lt->name = dh->name;
	lt->path = remplir_name(dh->fpath, dh->name);
	lt->av = dh->fpath;
	b = lstat(lt->path, &buf);
	lt->stmode = buf.st_mode;
	lt->stnlink = buf.st_nlink;
	lt->stuid = buf.st_uid;
	lt->stgid = buf.st_gid;
	lt->stsize = buf.st_size;
	lt->stmtime = buf.st_mtime;
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		majminvar_value(&(lt->majminvar), buf);
	lt->linkname = (S_ISLNK(lt->stmode)) ? (get_link(&buf, lt->path)) : (NULL);
	lt->hpmax = hpmax;
	lt->next = NULL;
	lt->prev = NULL;
	return (lt);
}

void		fill_hpmax(t_helpmax *hpmax, struct stat *buf, int n)
{
	t_passwd	*pwd;
	t_group		*grp;

	if (n == 1)
		hpmax->total += buf->st_blocks;
	if ((pwd = getpwuid(buf->st_uid)) != NULL)
	{
		if ((int)(ft_strlen(pwd->pw_name)) > hpmax->pwnmax)
			hpmax->pwnmax = ft_strlen(pwd->pw_name);
	}
	if ((grp = getgrgid(buf->st_gid)) != NULL)
	{
		if ((int)(ft_strlen(grp->gr_name)) > hpmax->grnmax)
			hpmax->grnmax = ft_strlen(grp->gr_name);
	}
	if (size_of_stsize(buf->st_size) > hpmax->sizemax)
		hpmax->sizemax = size_of_stsize(buf->st_size);
	if (size_of_stnlink(buf->st_nlink) > hpmax->linkmax)
		hpmax->linkmax = size_of_stnlink(buf->st_nlink);
	if (S_ISCHR(buf->st_mode) || S_ISBLK(buf->st_mode))
		fill_majmin(hpmax, buf);
}

char		*remplir_name(char *str1, char *str2)
{
	char	*str3;
	int		i;
	int		j;

	if (!(str3 = (char*)malloc(sizeof(char) * (ft_strlen(str1)
						+ ft_strlen(str2) + 2))))
		exit(1);
	i = 0;
	j = 0;
	while (str1[i])
		str3[j++] = str1[i++];
	if (str3[j - 1] != '/')
	{
		str3[j] = '/';
		j++;
	}
	i = 0;
	while (str2[i])
		str3[j++] = str2[i++];
	str3[j] = '\0';
	return (str3);
}
