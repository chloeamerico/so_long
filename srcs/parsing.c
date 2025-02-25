/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:15:10 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 15:30:09 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//fait attention qu'il n'y ait pas 2 sorties ou 2 personnage a l'ecran;
//si on va a la sortie sans que le collectible_left soit a 0 on ne fait rien
//la case suivante est la sortie et le collectible_left est a 0 , alors message : "you won"
// on initialise le collectible_left en comptant le nb de C sur la map initiale
// la carte doit etre entouree par des murs ==> sinon retourne une erreur
// la carte doit contenir un chemin valide


// si possible, on change l'orientation du pacman


//on compte le nombre de collectibles sur la map
// void	left_collecitble(char **map, t_game *game)
// {
// 	int	y = 0; //pour passer de ligne en ligne
// 	int	x; //pour parcourir tous les characteres de ma ligne

// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[x])
// 		{
// 			if (map[y][x] == 'C')
// 				game->collectible_left++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	// ft_printf("nb de collectible restant : %d\n", game->collectible_left);
// }

int	left_collecitble(char **map)
{
	int	y = 0; //pour passer de ligne en ligne
	int	x; //pour parcourir tous les characteres de ma ligne
	int count = 0;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	ft_printf("count collectible : %d\n", count);
	return(count);
}
