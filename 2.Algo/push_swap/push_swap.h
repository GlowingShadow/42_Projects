/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:44:29 by REDACTED          #+#    #+#             */
/*   Updated: 2015/03/17 23:58:20 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <string.h>
# define COLOR(X) ft_strcolor("\033[", X, "m")
# define BLACK "30"
# define RED "31"
# define GREEN "32"
# define YELLOW "33"
# define BLUE "34"
# define MAGENTA "35"
# define CYAN "36"
# define WHITE "37"

typedef struct	s_mvt
{
	int		count;
	char	*str;
}				t_mvt;

typedef struct	s_small
{
	int	i;
	int n;
}				t_small;

typedef struct	s_itab
{
	int	*tab;
	int	size;
}				t_itab;

typedef struct	s_env
{
	t_itab	pile1;
	t_itab	pile2;
	char	*opt;
	int		count;
	t_mvt	mvt;
	int 	start;
	int		ac;
	char	*op;
	int		oplen;
	char	*found;
}				t_env;

int				ft_isnumber(char *arg);
int				ft_check_integer(char *str);
void			ft_option(char *opt, t_mvt mvt, t_itab pile1, t_itab pile2);
t_mvt			ft_algo1(t_env e);
t_mvt			ft_algo2(t_env e, t_small sm, int i, int mid);
t_mvt			ft_algo3(t_env e, int i);
int				ft_check_sort_pile1(t_env e);
void			ft_putnbr_str(int *n);
t_itab			ft_atoi_tab(char **tab);
t_small			ft_find_smaller_int(int *tab, int size);
t_small			ft_find_bigger_int(int *tab, int size);
void			ft_put_smaller_on_top1(t_small sm, t_env *e);
void			ft_put_smaller_on_top2(t_small sm, t_env *e);
void			ft_sort_int_tab(int *tab, unsigned int size);
int				ft_check_sort_int_tab(int *tab, unsigned int size);
int				ft_check_rsort_int_tab(int *tab, unsigned int size);
int				ft_synth_option(int argc, char **argv, char **opt);
void			ft_valid_argv(char **av);
void			ft_clear_zero(char ***av);
void			ft_swap(t_itab *pile);
void			ft_sswap(t_itab *pile1, t_itab *pile2);
int				ft_push(t_itab *src, t_itab *dst);
void			ft_rot(t_itab *pile);
void			ft_rrot(t_itab *pile);
void			ft_rot_all(t_itab *pile1, t_itab *pile2);
void			ft_rrot_all(t_itab *pile1, t_itab *pile2);
void			ft_sa(t_env *e);
void			ft_sb(t_env *e);
void			ft_ra(t_env *e);
void			ft_rb(t_env *e);
void			ft_pa(t_env *e);
void			ft_pb(t_env *e);
void			ft_rra(t_env *e);
void			ft_rrb(t_env *e);
void			ft_rr(t_env *e);
void			ft_rrr(t_env *e);
char			*ft_read_op(char *str);
void			ft_intswap(int *i, int *j);
char			*ft_strjoin_free(char *s1, char *s2, int n);

int				ft_check_mvt(t_itab pile1, t_itab pile2, char *str);
t_itab			ft_int_tab_dup(int *tab, int size);
void			ft_putpile(t_itab pile);
void			ft_display(t_itab pile1, t_itab pile2);
#endif
