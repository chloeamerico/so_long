/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:15:55 by camerico          #+#    #+#             */
/*   Updated: 2025/02/25 15:18:08 by camerico         ###   ########.fr       */
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
	void 		*img_wall;
	void 		*img_floor;
	void		*img_collectible;
	void		*img_exit;
	void		*img_player;
} t_texture;


//va stocker toutes les infos necessaires au jeu
typedef struct s_game
{
	void		*mlx_ptr; 			//pointeur vers la mlx
	void		*win_ptr; 			//pointeur pour la fenetre
	char		**map; 				//tableau 2D qui va contenir la map
	int			player_x; 			//position x du payer
	int			player_y; 			//position y du player
	int			collectible_left; 	//nb de collectible qu'il reste a ramasser
	int			nb_mvmt;
	t_texture	*texture;
} t_game;

/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */

int	main(int argc, char **argv);
int	ESC(int keysym, t_game *data);
int	destroy(t_game *data);
void	load_sprites(t_game *game, t_texture *texture);
char	**load_map(char *filename);
void	put_image (t_game *game, char c, int x, int y, t_texture *texture);
void display_map(t_game *game, t_texture *texture);
int	key_hook(int keysym, t_game *game);
int	left_collecitble(char **map);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif