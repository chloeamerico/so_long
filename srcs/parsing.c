/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:15:10 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 18:26:59 by camerico         ###   ########.fr       */
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

int	verif_size_screen(int height, int width, t_game	*game)
{
	int	win_width; // la largeur que devrait faire notre map si elle s'affiche
	int win_height; // la hauteur que devrait faire notre map si elle s'affiche
	int max_width;
	int	max_height;

	win_width = width * 64;
	win_height = height * 64;

	// la fonction va recup la taille de l'ecran et la stocker dans max_width et max_height
	mlx_get_screen_size(game->mlx_ptr, &max_width, &max_height);

	if (win_width > max_width)
	{
		ft_printf("Error : map size too large to display\n");
		return (1);
	}
	if (win_height > max_height)
	{
		ft_printf("Error : map size too large to display\n");
		return (1);
	}
	return (0);
}
