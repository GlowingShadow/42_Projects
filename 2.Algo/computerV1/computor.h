/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 00:39:50 by REDACTED          #+#    #+#             */
/*   Updated: 2015/04/04 07:09:55 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_itab
{
	double	*itab;
	int	size;
}				t_itab;

typedef struct	s_env
{
	t_itab	power;
	t_itab	n;
	int		degree;
}				t_env;

int				ft_isoperand(char c);
char			**ft_cut(char *src);
int				ft_ispower(char *str);
int				ft_isoperand_str(char *str);
int				ft_isoperand(char c);
int				ft_ismult(char *str);
int				ft_isnumber(char *str);
void			ft_stock_value(t_env *e, char **tab);
void			ft_display(t_env e);
void			ft_solve(t_env e);
void			ft_delta(t_env e);
double			ft_fabs(double n);
double			ft_sqrt(double n);

#endif
