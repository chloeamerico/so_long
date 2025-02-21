/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:00:57 by camerico          #+#    #+#             */
/*   Updated: 2025/02/21 20:38:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// a utiliser quand une fenetre est fermee
int	destroy(t_game *game)
{
	int	i;
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

//keysym = identifiant de chaque touche du clavier
//la fonction explique ce qui sera fait quand une touche sera pressee
int	keypressed(int keysym, t_game *game)
{
	printf("Pressed key : %d\n", keysym);
	if (keysym == XK_Escape)
		destroy(game);
	return (0);
}

// //fonction qui permet de fermer la fenetre en appuyant sur ESC
// int keypressed2(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 		destroy(data);
// 	printf("Pressed key : %d\n", keysym);
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	data;
	
// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (1);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "test"); //pour creer une fenetre
// 	if (!data.win_ptr)
// 	{
// 		free(data.mlx_ptr);
// 		return (1);
// 	}
// 	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, keypressed, &data);
// 	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &data);
// 	mlx_loop(data.mlx_ptr);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_game	game;
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
	while (game.map[height])
		height++;
	while (game.map[width])
		width++;
	printf("%d -- %d\n", width, height); // ERREUR A FIX ICI LECTURE DE LA HAUTEUR ET LARGEUR
//on cree la fenetre
	game.win_ptr = mlx_new_window(game.mlx_ptr, width * 64, height * 64, "so_long"); //pour creer une fenetre
	if (!game.win_ptr)
	{
		free(game.map);
		return (1);
	}
	load_sprites(&game); // on charge les sprites
	display_map(&game); // on affiche la carte
//on gere les evenements de clavier et fermeture de la fenetre;
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, keypressed, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
