/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:21:40 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 14:53:51 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game, t_texture *texture)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	texture->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "texture/mur.xpm", &width, &height);
	texture->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr, "texture/piece.xpm", &width, &height);
	texture->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "texture/exit.xpm", &width, &height);
	texture->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "texture/vide.xpm", &width, &height);
	texture->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "texture/pacman.xpm", &width, &height);
}

// ouvre le fichier, lit la map ligne par ligne, et la transforme en tableau
char	**load_map(char *filename)
{
	int	fd;
	char	**map; //tableau pour stocker la map
	char	*line;
	int	i;

	fd = open(filename, O_RDONLY); //on ouvre le fichier en lecture seule
	if (fd < 0)
	{
		perror("Error opening map");
		return (NULL);
	}
	map = malloc(sizeof(char *) * 100); // ici 100 lignes max mais voir comment ajuster
	if (!map)
		return (NULL);
	i = 0;
	while((line = get_next_line(fd)))
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

// va associe a chaque char l'image correspondante
void	put_image (t_game *game, char c, int x, int y, t_texture *texture)
{
	void	*img;

	img = NULL;
	if (c == '1')
		img = texture->img_wall;
	else if (c == '0')
		img = texture->img_floor;
	else if (c == 'C')
		img = texture->img_collectible;
	else if (c == 'E')
		img = texture->img_exit;
	else if (c == 'P')
		img = texture->img_player;
	if (img) // si img n'est pas NULL on affiche l'image
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x * 64, y * 64);
	return;
}


// fonction pour afficher la map
void display_map(t_game *game, t_texture *texture)
{
	int	x; //variables pour parcourir la map
	int	y;

	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	y = 0; //commence a la premiere ligne
	while (game->map[y]) //tant qu'il y a une ligne
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n') //tant qu'il y a un char et qu'il est != de '\n'
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			put_image(game, game->map[y][x], x, y, texture);
			x++;
		}
		y++;
	}
}
