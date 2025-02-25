/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:00:57 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 19:00:35 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// a utiliser quand une fenetre est fermee
int	destroy(t_game *game)
{
	int	i;
	free_textures(game, game->texture);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
// on libere la map	
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit (0);
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

int	main(int argc, char **argv)
{
	t_game	game;
	// t_game	texture;
	int width;
	int	height;
	
	if (argc != 2)
	{
		ft_printf("Error : too many arguments\n");
		return (1);
	}
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
// chargement de la map
	game.map = load_map(argv[1]);
	if(!game.map)
	{
		ft_printf("Error : Failed to load map\n");
		return (1);
	}
// determine la taille de la fenetre en fonction de la map;
	width = 0;
	height = 0;
	game.nb_mvmt = 0;
	while (game.map[height])
	{
		if ((int) ft_strlen(game.map[height]) > width)
			width = (int) ft_strlen(game.map[height]) - 1;
		height++;
	}
	if (check_wall(game.map, width, height) != 0)
		return (0);
	if (parsing_position_double(game.map) != 0)
		return (0);
	if (verif_size_screen(height, width, &game) != 0)
		return (0);
//on cree la fenetre
	game.win_ptr = mlx_new_window(game.mlx_ptr, width * 64, height * 64, "so_long"); //pour creer une fenetre
	if (!game.win_ptr)
	{
		free(game.map);
		return (1);
	}
	game.texture = malloc(sizeof(t_texture));
	if (!game.texture)
		return (1);
	load_sprites(&game, game.texture); // on charge les sprites
	display_map(&game, game.texture); // on affiche la carte
	//on gere les evenements de clavier et fermeture de la fenetre;
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, key_hook, &game);
	game.collectible_left = left_collecitble(game.map);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
