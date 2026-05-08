/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idee.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 11:29:58 by REDACTED          #+#    #+#             */
/*   Updated: 2015/06/04 07:32:19 by REDACTED         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


technique de trace:
	raycasting:
		-x rayons (x = win_x), 1 rayon/pixel
		-2 rayons par cube, afin d'obtenir l inclinaison du mur et tracer intelligents
			ou: 2 rayon sur chaque coin, miroir horiz et fdf sur les 4pts obtenus
			remplissage (par region ou technique intersection des cote du carre)
Comparer les ressources utilisees pour les calculs.

bonus:
	textures
		avec la coordonnee du mur, trouver sa position relative % debut du mur,
		prendre, avec la meme proportion, la bonne colone de la texture
		puis la dessiner avec la bonne taille, produit en croix

	portal
	RPG:
		passage secret:
			mur sans hitbox (traversable)
			porte, serrures
		objet ramassable
		npc
		combats
	cuda
	lampe torche:
		-recupere le ptr *pixel de limage:
			while (cercle de centre 'milieu de la fenetre')
			{
				sur tous les points add X aux couleurs RGB du pix(255 max)
			}
	bazooka: meme algo detection mur, set map->wall = 0, redraw
		/image se deplace jusqu au mur, puis boom
		/image qui retrecie jusqu a une certaine valeur (en fonction de la distance du mur), puis boom


Ressources: alonerone YT
say -v Boing "Welcome to wolf3d"
say -v "Good News" "welcome to wolf3d"
say -v Zarvox "Welcome to wolf3d"
