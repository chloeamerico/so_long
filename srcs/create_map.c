/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:21:40 by camerico          #+#    #+#             */
/*   Updated: 2025/02/28 17:33:39 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//trsnforme le fichier xpm en image, et verifie au'on peut bien lire l'image
static int	load_texture(t_game *game, void **img, char *path)
{
	int	width;
	int	height;
	int fd;

	width = 64;
	height = 64;
	*img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error : failed to load texture");
		destroy (game);
		return (1);
	}
	close(fd);
	return (0);
}

int	load_sprites(t_game *game, t_texture *texture)
{
	if (load_texture(game, &texture->img_wall, "texture/mur.xpm") != 0)
		return (1);
	if (load_texture(game, &texture->img_collectible, "texture/piece.xpm") != 0)
		return (1);
	if (load_texture(game, &texture->img_exit, "texture/exit.xpm") != 0)
		return (1);
	if (load_texture(game, &texture->img_floor, "texture/vide.xpm") != 0)
		return (1);
	if (load_texture(game, &texture->img_player, "texture/pacman_jambes.xpm") != 0)
		return (1);
	return (0);
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
		return (perror("Error opening map"), NULL);
	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}

// va associe a chaque char l'image correspondante
int	put_image(t_game *game, char c, int x, int y)
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
	return (0);
}

// fonction pour afficher la map
int	display_map(t_game *game)
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
			if (put_image(game, game->map[y][x], x, y) != 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
