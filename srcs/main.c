/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:00:57 by camerico          #+#    #+#             */
/*   Updated: 2025/02/27 14:59:30 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_and_load(t_game *game, int argc, char **argv)
{
	game->texture = NULL;
	game->win_ptr = NULL;
	game->nb_mvmt = 0;
	if (argc != 2)
	{
		ft_printf("Error : too many arguments\n");
		return (1);
	}
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->map = load_map(argv[1]);
	if (!game->map)
	{
		ft_printf("Error : Failed to load map\n");
		destroy(game);
		return (1);
	}
	return (0);
}

int	validate_map(t_game *game, int *width, int *height)
{
	int	len;

	*width = 0;
	*height = 0;
	while (game->map[*height])
	{
		len = (int)ft_strlen(game->map[*height]) - 1;
		if (len > *width)
			*width = len;
		(*height)++;
	}
	if (parsing_elemts(game->map, *width, *height) != 0
		|| verif_size_screen(*height, *width, game) != 0)
	{
		destroy(game);
		return (1);
	}
	return (0);
}

int	setup_window_and_textures(t_game *game, int width, int height)
{
	int	w;
	int	h;

	w = width * 64;
	h = height * 64;
	game->win_ptr = mlx_new_window(game->mlx_ptr, w, h, "so_long");
	if (!game->win_ptr)
	{
		destroy(game);
		return (1);
	}
	game->texture = malloc(sizeof(t_texture));
	if (!game->texture)
	{
		destroy(game);
		return (1);
	}
	load_sprites(game, game->texture);
	display_map(game, game->texture);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		width;
	int		height;

	if (init_and_load(&game, argc, argv) != 0)
		return (1);
	if (validate_map(&game, &width, &height) != 0)
		return (1);
	if (setup_window_and_textures(&game, width, height) != 0)
		return (1);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, key_hook, &game);
	game.collectible_left = left_collecitble(game.map);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
