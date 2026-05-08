/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:40:37 by REDACTED          #+#    #+#             */
/*   Updated: 2016/02/13 19:40:41 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define OK				0
# define BAD_ARG		1
# define OPEN_FAILED	2
# define INVALID_LINE	3
# define INVALID_PIECE	4

typedef struct	s_fln
{
	char		letter;
	int			left;
	int			lefty;
}				t_fln;

typedef struct	s_env
{
	char		list[19][17];
	char		pieces[27][17];
}				t_env;

void			error(char *msg, int error_code);
void			get_map(t_env *e, char *file);
void			adjust_map(t_env *e);
void			result(t_env *e);
void			print_result(char *map, int size);

#endif
