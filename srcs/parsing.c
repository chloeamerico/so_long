/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:15:10 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 16:54:01 by camerico         ###   ########.fr       */
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

// faire en sorte que lorsque pcman sort par exit, le sprite sortie soit remplace par pacman
//comme si il avancait vraiemt dessus
// j'avais fait ca (dans UP) mais ca marchait pas 
// else
// 		{
// 			game->map[y][x] = '0';
// 			game->map[y - 1][x] = 'P';
// 			game->player_y = y - 1;
// 			ft_printf("Congratulations, you've won\n");
// 			destroy(game);
// 		}



//on compte le nombre de collectibles sur la map
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
	return(count);
}

//verifie si la map est entouree de murs 
int check_wall(char **map, int width, int height)
{
	int y = 0;
	int x = 0;
	
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
		{
			ft_printf("Error: the map must be surrounded by walls.\n");
			return (1);
		}
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
		{
			ft_printf("Error: the map must be surrounded by walls.\n");
			return (1);
		}
		y++;
	}
	return (0);
}
