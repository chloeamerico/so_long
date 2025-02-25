/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:15:10 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 17:38:18 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// la carte doit contenir un chemin valide
// taille de l'ecran


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

// verifie s'il n'y a pas 2 P ni 2 E sur la map
int	parsing_position_double(char **map)
{
	int	x;
	int	y = 0;
	int P = 0;
	int E = 0;
	
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				P++;
			if (map[y][x] == 'E')
				E++;
			x++;
		}
		y++;
	}
	if (P != 1 || E != 1)
	{
		ft_printf("Error : the map is invalid");
		return (1) ;
	}
	return (0);
}
