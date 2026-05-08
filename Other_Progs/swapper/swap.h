/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:19:44 by REDACTED          #+#    #+#             */
/*   Updated: 2015/01/27 12:30:02 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	char	**pile1;
	char	**pile2;
}				t_env;

#endif
/*

sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
(ne fait rien s’il n’y en a qu’un ou aucun).
◦ sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.
(ne fait rien s’il n’y en a qu’un ou aucun).
◦ ss : sa et sb en même temps.
◦ pa : push a - prend le premier élément au sommet de b et le met sur a.
(ne fait rien si b est vide).
◦ pb : push b - prend le premier élément au sommet de a et le met sur b.
(ne fait rien si a est vide).
◦ ra : rotate a - décale d’une position tous les élements de la pile a.
(vers le haut, le premier élément devient le dernier).
◦ rb : rotate b - décale d’une position tous les élements de la pile b.
(vers le haut, le premier élément devient le dernier).
◦ rr : ra et rb en meme temps.
◦ rra : reverse rotate a
(vers le bas, le dernier élément devient le premier).
◦ rrb : reverse rotate b
(vers le bas, le dernier élément devient le premier).
◦ rrr : rra et rrb en même temps.

*/
