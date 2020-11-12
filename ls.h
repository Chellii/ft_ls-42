/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:29:42 by cel-oiri          #+#    #+#             */
/*   Updated: 2019/11/23 06:56:13 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>

# define LS_A 1
# define LS_L 2
# define LS_R 4
# define LS_T 8
# define LS_BR 16

typedef struct group	t_group;
typedef struct passwd	t_passwd;
typedef struct dirent	t_dirent;

typedef struct			s_helpmax
{
	int				linkmax;
	int				sizemax;
	int				pwnmax;
	int				grnmax;
	int				majmax;
	int				minmax;
	int				majmin;
	blkcnt_t		total;
}						t_helpmax;

typedef struct			s_majminvar
{
	int	maj;
	int	min;
}						t_majminvar;

typedef	struct			s_dirent_h
{
	char			*name;
	char			*fpath;
	unsigned char	dtype;
}						t_dirent_h;

typedef struct			s_list_ls
{
	char				*av;
	char				*name;
	t_helpmax			*hpmax;
	char				*linkname;
	char				*path;
	unsigned char		dtype;
	gid_t				stgid;
	mode_t				stmode;
	time_t				stmtime;
	nlink_t				stnlink;
	off_t				stsize;
	uid_t				stuid;
	dev_t				strdev;
	t_majminvar			majminvar;
	struct s_list_ls	*next;
	struct s_list_ls	*prev;
}						t_list_ls;

typedef struct			s_tabav_lt
{
	char				*nameav;
	int					exist;
	int					t_errno;
	struct stat			buf;
	struct s_tabav_lt	*next;
	struct s_tabav_lt	*prev;
}						t_tabav_lt;

typedef struct			s_pars_v
{
	int			pars_var;
	int			flags;
	int			spec_case;
	int			dir_case;
	int			nb_dir;
	t_helpmax	*hpmax;
	t_helpmax	*hpmax_file;
	t_dirent_h	*dh;
	t_tabav_lt	*t;
}						t_pars_v;

typedef struct			s_rdir
{
	DIR				*rep;
	t_dirent		*d;
	char			*path;
	int				b;
	struct stat		buf;
}						t_rdir;
void					free_pv_path(t_pars_v *pv, char *path);
t_tabav_lt				*allocate_case_list(char *str);
char					*concat_str(char *str1, char *str2);
t_list_ls				*error_directory(char *nameav);
t_list_ls				*fill_lt(t_dirent_h *dh, t_helpmax *hpmax);
t_tabav_lt				*fill_ltav(t_tabav_lt **t, char *str, t_pars_v *pv);
t_tabav_lt				*fill_ltav_ft(t_tabav_lt **t, char *str, t_pars_v *pv);
t_tabav_lt				*fill_ltav_r(t_tabav_lt **t, char *str, t_pars_v *pv);
t_tabav_lt				*fill_ltav_rft(t_tabav_lt **t, char *str, t_pars_v *pv);
char					*get_link(struct stat *buf, char *path);
t_tabav_lt				*insert_dir_tf(t_tabav_lt **t, t_tabav_lt *lt);
t_tabav_lt				*insert_files_tf(t_tabav_lt **t, t_tabav_lt *lt);
t_tabav_lt				*insert_inexist_df(t_tabav_lt **t, t_tabav_lt *lt);
t_tabav_lt				*insert_mid(t_tabav_lt *lt2, t_tabav_lt *lt);
t_list_ls				*insert_mid_list(t_list_ls *lt2, t_list_ls *lt);
t_list_ls				*ltinsr(t_list_ls **lt, t_pars_v *pv);
t_list_ls				*ltinsr_r(t_list_ls **lt, t_dirent_h *dh,
		t_helpmax *hpmax);
t_list_ls				*ltinsrt(t_list_ls **lt, t_dirent_h *dh);
t_list_ls				*ltinsr_tflag(t_list_ls **lt, t_pars_v *pv);
char					*remplir_name(char *str1, char *str2);
t_list_ls				*reverse_list_r(t_list_ls **lt);
t_tabav_lt				*reverse_rf(t_tabav_lt **t);
void					affich_list(t_list_ls *lt);
void					affich_list_a(t_list_ls *lt);
void					affich_list_abr(t_list_ls *lt);
void					affich_list_br(t_list_ls *lt);
void					affich_list_l(t_list_ls *lt);
void					afficher_list_al(t_list_ls *lt);
int						cal_flags(char *f);
int						case_dir_nb(int ac, char **av, t_pars_v *pv);
void					create_lt(t_pars_v *pv);
int						cmp_mtime(struct stat buf1, struct stat buf2);
void					fill_hpmax(t_helpmax *hpmax, struct stat *buf, int n);
int						ft_tablen(char **tab);
void					free_pv(t_pars_v *pv);
void					freelist(t_list_ls **lt);
void					gest_error(int x, char f);
void					init_f(t_pars_v *pv);
void					init_hpmax(t_helpmax *hpmax);
void					init_majminvar(t_majminvar *majminvar);
void					insert_end(t_tabav_lt *lt2, t_tabav_lt *lt);
void					insert_end_list(t_list_ls *lt2, t_list_ls *lt);
void					insertion(t_list_ls **lt, char *av);
int						is_dir(int n, char **av, int spec_case);
int						isdir(struct stat buf);
int						lst_len(t_tabav_lt *t);
void					majminvar_value(t_majminvar *mvar, struct stat buf);
void					pars_directory(int ac, char **av, t_pars_v *pv);
void					pars_flags(char **av, t_pars_v *pv);
void					parsing(t_pars_v *pv, int ac, char **av);
void					permission(mode_t stmode);
void					read_dir(t_list_ls **lt, t_pars_v *pv, char *nameav);
void					read_dir_br(t_list_ls *lt, t_pars_v *pv);
void					show_ctime(time_t stmtime);
void					show_file_lf(t_tabav_lt *t1, t_pars_v *pv);
void					show_files_list(t_tabav_lt *t1, t_pars_v *pv);
void					show_grname(t_list_ls *lt, int grnmax);
void					show_grname_file(gid_t stgid, int grnmax);
void					show_pwname(t_list_ls *lt, int pwnmax);
void					show_pwname_file(uid_t stuid, int pwnmax);
void					show_stsize(off_t stsize, t_majminvar majminvar,
		mode_t stmode, t_helpmax *hpmax);
void					show_stnlink(nlink_t stnlink, int linkmax);
int						size_nbr_int(int nbr);
int						size_of_majmin(int majmax, int minmax);
int						size_of_stnlink(nlink_t stlink);
int						size_of_stsize(off_t stsize);
void					sort_time(t_list_ls *lt);
int						verif_flags(char f);
#endif
