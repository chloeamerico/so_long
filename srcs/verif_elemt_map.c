/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elemt_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:44:54 by camerico          #+#    #+#             */
/*   Updated: 2025/02/26 17:37:36 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifie si la map est entouree de murs 
int	check_wall(char **map, int width, int height)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
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

// verifie s'il n'y a pas 2 E sur la map
int	parsing_double_exit(char **map)
{
	int	x;
	int	y;
	int	e;

	y = 0;
	e = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	if (e != 1)
	{
		ft_printf("Error : the map must contain 1 exit\n");
		return (1);
	}
	return (0);
}

//verifie s'il n'y a pas 2 P sur la map
int	parsing_double_pacman(char **map)
{
	int	x;
	int	y;
	int	p;

	y = 0;
	p = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p++;
			x++;
		}
		y++;
	}
	if (p != 1)
	{
		ft_printf("Error :  the map must contain 1 Pacman\n");
		return (1);
	}
	return (0);
}

//fonction qui verifie qu'il y ait au moins 1 collectible
int	parsing_double_collectible(char **map)
{
	int	x;
	int	y;
	int	collectible;

	y = 0;
	collectible = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	if (collectible == 0)
	{
		ft_printf("Error : the map must contain at least 1 collectible \n");
		return (1);
	}
	return (0);
}

int	parsing_elemts(char **map, int width, int height)
{
	if (check_wall(map, width, height) != 0)
		return (1);
	if (parsing_double_exit(map) != 0)
		return (1);
	if (parsing_double_pacman(map) != 0)
		return (1);
	if (parsing_double_collectible(map) != 0)
		return (1);
	return (0);
}
