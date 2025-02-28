/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:00:57 by camerico          #+#    #+#             */
/*   Updated: 2025/02/28 18:34:13 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_and_load(t_game *game, int argc, char **argv)
{
	game->texture = NULL;
	game->win_ptr = NULL;
	game->nb_mvmt = 0;
	game->map = NULL;
	if (argc != 2)
	{
		ft_printf("Error : too many arguments\n");
		return (1);
	}
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
		return (ft_printf("Error : doesn't finish with a '.ber'\n"), \
			destroy(game), 1);
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
	game->height = *height;
	game->width = *width;
	if (valid_path(game) == 1)
		return (destroy(game), 1);
	if (parsing_elemts(game->map, *width, *height) != 0
		|| verif_size_screen(*height, *width, game) != 0)
		return (destroy(game), 1);
	return (0);
}

int	setup_window_and_textures(t_game *game, int width, int height)
{
	int	w;
	int	h;

	w = width * 64;
	h = height * 64;
	game->texture = ft_calloc(sizeof(t_texture), 100);
	if (!game->texture)
	{
		destroy(game);
		return (1);
	}
	if (load_sprites(game, game->texture) == 1)
		return (destroy(game), 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, w, h, "so_long");
	if (!game->win_ptr)
	{
		destroy(game);
		return (1);
	}
	display_map(game);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;
	int		width;
	int		height;

	if (!envp || !*envp)
		return (ft_printf("Error : There is no environment\n"), 1);
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
