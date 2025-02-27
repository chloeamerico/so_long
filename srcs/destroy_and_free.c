/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:07:05 by camerico          #+#    #+#             */
/*   Updated: 2025/02/27 14:57:57 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_game *game)
{
	int	i;

	if (game->texture)
		free_textures(game, game->texture);
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_textures(t_game *game, t_texture *texture)
{
	if (texture->img_wall)
		mlx_destroy_image(game->mlx_ptr, texture->img_wall);
	if (texture->img_collectible)
		mlx_destroy_image(game->mlx_ptr, texture->img_collectible);
	if (texture->img_exit)
		mlx_destroy_image(game->mlx_ptr, texture->img_exit);
	if (texture->img_floor)
		mlx_destroy_image(game->mlx_ptr, texture->img_floor);
	if (texture->img_player)
		mlx_destroy_image(game->mlx_ptr, texture->img_player);
	free(texture);
}
