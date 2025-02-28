/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:15:10 by camerico          #+#    #+#             */
/*   Updated: 2025/02/28 18:30:34 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//on compte le nombre de collectibles sur la map
int	left_collecitble(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
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
	return (count);
}

int	verif_size_screen(int height, int width, t_game	*game)
{
	int	win_width;
	int	win_height;
	int	max_width;
	int	max_height;

	win_width = width * 64;
	win_height = height * 64;
	mlx_get_screen_size(game->mlx_ptr, &max_width, &max_height);
	if (win_width > max_width)
	{
		ft_printf("Error : map size is incorrect\n");
		return (1);
	}
	if (win_height > max_height)
	{
		ft_printf("Error : map size too large to display\n");
		return (1);
	}
	return (0);
}
