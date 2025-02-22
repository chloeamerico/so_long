/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:35:59 by camerico          #+#    #+#             */
/*   Updated: 2025/02/22 20:03:15 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//keysym = identifiant de chaque touche du clavier
//la fonction explique ce qui sera fait quand une touche sera pressee
int	ESC(int keysym, t_game *game)
{
	printf("Pressed key : %d\n", keysym);
	if (keysym == XK_Escape)
		destroy(game);
	return (0);
}

void	UP(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	
	if (game->map[y - 1][x] == '1')
        return;
	if (game->map[y - 1][x] == 'C')
	{
		game->collectible_left--;
	}
	game->map[y - 1][x] = 'P';
	game->map[y][x] = '0';
	game->player_y = y - 1;
}

void	DOWN(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	
	if (game->map[y + 1][x] == '1')
        return;
	if (game->map[y + 1][x] == 'C')
	{
		game->collectible_left--;
	}
	game->map[y + 1][x] = 'P';
	game->map[y][x] = '0';
	game->player_y = y + 1;
}

void	LEFT(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	
	if (game->map[y][x - 1] == '1')
        return;
	if (game->map[y][x - 1] == 'C')
	{
		game->collectible_left--;
	}
	game->map[y][x - 1] = 'P';
	game->map[y][x] = '0';
	game->player_x = x - 1;
}

void	RIGHT(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	
	if (game->map[y][x + 1] == '1')
        return;
	if (game->map[y][x + 1] == 'C')
	{
		game->collectible_left--;
	}
	game->map[y][x + 1] = 'P';
	game->map[y][x] = '0';
	game->player_x = x + 1;
}

void	mouvements(int keysym, t_game *game)
{	
	if (keysym == 'w' || keysym == 'W')
		UP(game);
	else if (keysym == 's' || keysym == 'S')
		DOWN(game);
	else if (keysym == 'a' || keysym == 'A')
		LEFT(game);
	else if (keysym == 'd' || keysym == 'D')
		RIGHT(game);
}
	
	// 	if (case[x][y - 1] == SOL ou COLL)
	// 		change_map(player, x, y - 1); // => game.map[x][y] = G && game.map[x][y - 1] = P
	// if (keysym == DOWN)
	// 	if (case[x][y + 1] == SOL ou COLL)
	// 		change_map(player, x, y + 1); // => game.map[x][y] = G && game.map[x][y + 1] = P
	// if (keysym == LEFT)
	// 	if (case[x - 1][y] == SOL ou COLL)
	// 		change_map(player, x - 1, y); // => game.map[x][y] = G && game.map[x - 1][y] = P
	// if (keysym == UP)
	// 	if (case[x + 1][y] == SOL ou COLL)
	// 		change_map(player, x + 1, y); // => game.map[x][y] = G && game.map[x + 1][y] = P
	// print_mouv(++game.mouv_num) // -> printf("Mouvement count : %d\r", game.mouv_num) 




// int	keypressed(int keysym, t_game *game)
// {
// 	// if (keysym == UP)
// 	// 	if (case[x][y - 1] == SOL ou COLL)
// 	// 		change_map(player, x, y - 1); // => game.map[x][y] = G && game.map[x][y - 1] = P
// 	// if (keysym == DOWN)
// 	// 	if (case[x][y + 1] == SOL ou COLL)
// 	// 		change_map(player, x, y + 1); // => game.map[x][y] = G && game.map[x][y + 1] = P
// 	// if (keysym == LEFT)
// 	// 	if (case[x - 1][y] == SOL ou COLL)
// 	// 		change_map(player, x - 1, y); // => game.map[x][y] = G && game.map[x - 1][y] = P
// 	// if (keysym == UP)
// 	// 	if (case[x + 1][y] == SOL ou COLL)
// 	// 		change_map(player, x + 1, y); // => game.map[x][y] = G && game.map[x + 1][y] = P
// 	if (keysym == XK_Escape)
// 		destroy(game);
// 	// print_mouv(++game.mouv_num) // -> printf("Mouvement count : %d\r", game.mouv_num) 
// 	return (0);
// }