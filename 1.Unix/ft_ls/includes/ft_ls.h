/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:10:52 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 04:03:43 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

typedef struct stat	t_stat;
typedef struct	s_data
{
	char		*file;
	char		*symlink;
	char		*fmode;
	int			links;
	char		*owner;
	char		*group;
	long long	bytes;
	int			major;
	int			minor;
	char		*date;
	time_t		*epoch;
	int			int_epoch;
	int			block;
}				t_data;

int				ft_ls(char **argv, int argc);
int				ft_synth_option(int argc, char **argv, char **opt);
int				ft_print_tab(char ***tab, char **opt);
int				ft_print_tab_dir(char ***tab, char **opt);
int				ft_print_tab_target(char ***tab, char **opt);
int				ft_lsa(char ***tab, char *dir);
void			ft_strswap(char **s1, char **s2);
void			ft_stats_swap(t_data **stats, int i, int len);
int				ft_tablen(char **tab);
int				ft_newtablen(char **argv, int argc, int i);
char			**ft_grep(char **tab, char **argv, int argc, int i);
void			ft_next_file(int *i, int *x);
int				ft_checksort(char **tab);
int				ft_checksort_epoch(t_data *statst, char ***tab);
void			ft_transfer(char ***tab, t_data *stats);
void			ft_tabsort(char ***tab);
void			ft_tabsort_epoch(char ***tab, t_data *statst);
DIR				*ft_opendir(char *dir);
void			ft_puttab(char **tab);
void			ft_puttab_target(char **tab, char *opt);
char			**ft_maketab_ls(char ***tab);
char			**ft_maketab_lsr(char ***tab);
char			**ft_maketab_lst(char ***tab);
t_data			*ft_maketab_lsl(char ***tab);
char			*ft_readlink(char *file);
char			*ft_grep_name(char *s);
char			*ft_synth(char *arg);
char			*ft_synth2(char *arg, char **s);
t_data			*ft_option(char ***tab, char *opt);
int				ft_get_stats(t_data *stats, char **tab);
char			*ft_get_time(t_data *stats);
char			*ft_perm(struct stat *buf);
void			ft_puttab_stats(t_data *stats, char **tab, int i, int j);
void			ft_puttab_stats_dir(t_data *stats, char **tab, int i, int j);
void			ft_puttab_stats_target(t_data *stats, int i, int j);
int				ft_isdev(t_data *stats, int j);
void			ft_put_bytes_dev(t_data *stats, int i, int j, int *lens);
void			ft_put_bytes(t_data *stats, int i, int *lens);
int				ft_max_links_len_target(t_data *stats, int j);
int				ft_max_links_len(t_data *stats, int j);
int				ft_max_owner_len_target(t_data *stats, int j);
int				ft_max_owner_len(t_data *stats, int j);
int				ft_max_group_len_target(t_data *stats, int j);
int				ft_max_group_len(t_data *stats, int j);
int				ft_max_bytes_len_target(t_data *stats, int j);
int				ft_max_bytes_len(t_data *stats, int j);
int				ft_max_major_len(t_data *stats, int j);
int				ft_max_minor_len(t_data *stats, int j);
void			ft_nputchar(char c, int n);
int				ft_isdirectory(char *str);
int				ft_islink(char *str);
int				ft_count_dir(char **tab, char *opt);
char			**ft_maketab_dir(char ***tab, char *opt);
int				ft_ls_dir(char **dir, char *opt, char **argv);
int				ft_ls_recursive(char **dir, char *opt, char **argv);
void			ft_clear_tab(char ***tab);
void			ft_clear_stats(t_data **stats, int len);
void			ft_bad_argument(char **argv);
void			ft_exist_error(char **argv);
int				ft_exist(char *arg);
char			**ft_tabjoin(char *s, char **tab);
void			ft_no_path(char ***tab);
void			ft_clear_epoch(t_data **stats, int len);
int				ft_recursive(char **dir, char *opt);
void			ft_bigputnbr(long long n);
int				ft_file_argv(char **argv);
char			*ft_strjoin_free(char *s1, char *s2, int n);
void			ft_put2str(char *s1, char *s2);
int				*ft_max_lens(t_data *stats, int j);

#endif
