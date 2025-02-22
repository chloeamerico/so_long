/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:15:55 by camerico          #+#    #+#             */
/*   Updated: 2025/02/22 16:36:25 by camerico         ###   ########.fr       */
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


//va stocker toutes les infos necessaires au jeu
typedef struct s_game
{
	void *mlx_ptr; //pointeur vers la mlx
	void *win_ptr; //pointeur pour la fenetre
	void *img_wall;
	void *img_floor;
	void *img_collectible;
	void *img_exit;
	void *img_player;
	char **map; //tableau 2D qui va contenir la map
} t_game;



/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */

int	main(int argc, char **argv);
int	keypressed(int keysym, t_game *data);
int	destroy(t_game *data);
void	load_sprites(t_game *game);
char	**load_map(char *filename);
void	put_image (t_game *game, char c, int x, int y);
void display_map(t_game *game);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif