/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:21:40 by camerico          #+#    #+#             */
/*   Updated: 2025/02/27 15:54:34 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_texture(t_game *game, void **img, char *path)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	*img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!img)
	{
		ft_printf("Error : failed to load texture: %s\n", path);
		exit(EXIT_FAILURE);
	}
}

void	load_sprites(t_game *game, t_texture *texture)
{
	load_texture(game, &texture->img_wall, "texture/mur.xpm");
	load_texture(game, &texture->img_collectible, "texture/piece.xpm");
	load_texture(game, &texture->img_exit, "texture/exit.xpm");
	load_texture(game, &texture->img_floor, "texture/vide.xpm");
	load_texture(game, &texture->img_player, "texture/pacman_jambes.xpm");
}

// ouvre le fichier, lit la map ligne par ligne, et la transforme en tableau
char	**load_map(char *filename)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map");
		return (NULL);
	}
	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	line = "a";
	while (line)
	{
		line = get_next_line(fd);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

// va associe a chaque char l'image correspondante
void	put_image(t_game *game, char c, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	w = x * 64;
	h = y * 64;
	img = NULL;
	if (c == '1')
		img = game->texture->img_wall;
	else if (c == '0')
		img = game->texture->img_floor;
	else if (c == 'C')
		img = game->texture->img_collectible;
	else if (c == 'E')
		img = game->texture->img_exit;
	else if (c == 'P')
		img = game->texture->img_player;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, w, h);
	return ;
}

// fonction pour afficher la map
void	display_map(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			put_image(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
