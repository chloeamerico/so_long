/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:15:55 by camerico          #+#    #+#             */
/*   Updated: 2025/02/28 18:34:48 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/* INCLUDES                                                                   */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/includes/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* STRUCTURES                                                                 */
/* ************************************************************************** */

// typedef struct s_data
// {
// 	void *mlx_ptr;
// 	void *win_ptr; 
// } t_data;

typedef struct s_texture
{
	void		*img_wall;
	void		*img_floor;
	void		*img_collectible;
	void		*img_exit;
	void		*img_player;
}	t_texture;

//va stocker toutes les infos necessaires au jeu
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			player_x;
	int			player_y;
	int			collectible_left;
	int			nb_mvmt;
	t_texture	*texture;
	int			height;
	int			width;
}	t_game;

/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */

int		destroy(t_game *data);
int		load_sprites(t_game *game, t_texture *texture);
char	**load_map(char *filename);
int		put_image(t_game *game, char c, int x, int y);
int		display_map(t_game *game);
int		key_hook(int keysym, t_game *game);
int		left_collecitble(char **map);
int		verif_size_screen(int height, int width, t_game	*game);
void	free_textures(t_game *game, t_texture *texture);
int		parsing_elemts(char **map, int width, int height);
int		setup_window_and_textures(t_game *game, int width, int height);
int		validate_map(t_game *game, int *width, int *height);
int		init_and_load(t_game *game, int argc, char **argv);
void	free_map(char **map);
char	**copy_map(char **map);
void	flood_fill(char **map, int x, int y, t_game *game);
int		valid_path(t_game *game);
void	find_initial_position(t_game *game);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif